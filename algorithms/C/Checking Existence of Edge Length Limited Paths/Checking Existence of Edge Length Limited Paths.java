class Solution {
    private int[] parents;
    public boolean[] distanceLimitedPathsExist(int n, int[][] edgeList, int[][] queries) {
        this.parents = new int[n];
        for (int i = 0; i < n; i++) parents[i] = i;
        
        int m = queries.length;
        
        // storing {u, v, weight, original idx} by increasing weight
        int[][] sortedQueries = new int[m][4];
        for (int i = 0; i < m; i++) {
            sortedQueries[i] = new int[]{queries[i][0], queries[i][1], queries[i][2], i};
        }
        Arrays.sort(sortedQueries, (a,b) -> a[2] - b[2]);
        
        
        // sort edgeList by increasing weight 
        Arrays.sort(edgeList, (a,b) -> a[2] - b[2]);
        int idx = 0;
        
        boolean[] res = new boolean[m];
        
        for (int i = 0; i < m; i++) {
            int[] q = sortedQueries[i];
            int w = q[2];
            
            // union all edges with weight less than current query
            while (idx < edgeList.length && edgeList[idx][2] < w) {
                int[] e = edgeList[idx++];
                int u = e[0], v = e[1];
                union(u, v);
            }
            
            int uQuery = q[0], vQuery = q[1], id = q[3];
            res[id] = (find(uQuery) == find(vQuery));
        }
        
        return res;
    }
    
    private void union(int u, int v) {
        int uParent = find(u);
        int vParent = find(v);
        parents[uParent] = vParent;
    }
    
    private int find(int u) {
        while (u != parents[u]) {
            parents[u] = parents[parents[u]];
            u = parents[u];
        }
        return u;
    }  
}
