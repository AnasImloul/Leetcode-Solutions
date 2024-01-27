// Runtime: 36 ms (Top 100.0%) | Memory: 107.50 MB (Top 100.0%)

class Solution {
    public int rootCount(int[][] eg, int[][] gu, int k) {
        // number of nodes
        int n = eg.length+1;
        // graph
        List<Integer>[] g = new List[n];
        for(int i = 0; i<n; i++) g[i] = new LinkedList<>();
        for(int[] a: eg){
            g[a[0]].add(a[1]);
            g[a[1]].add(a[0]);
        }
        // counter for outside the subtree
        int all = 0;
        // counter for inside the subtree and parent list
        int[] add = new int[n], par = new int[n];
        // calculate parents
        dfs1(g, 0, -1, par);
        for(int[] a: gu) if(par[a[1]] == a[0]){
            // add one to outside the subtree
            all++;
            add[a[1]]--;
        }else // add one to inside the subtree
        add[a[0]]++;
        // calculate total sums
        dfs2(g, 0, -1, add);
        int ans = 0;
        for(int i: add) if(i+all >= k) ans++;
        return ans;
    }
    private void dfs1(List<Integer>[] g, int s, int p, int[] par){
        par[s] = p;
        for(int i: g[s]) if(i != p) dfs1(g, i, s, par);
    }
    private void dfs2(List<Integer>[] g, int s, int p, int[] add){
        for(int i: g[s]) if(i != p){
            // sum of everything above it, to calculate total sums
            add[i]+=add[s];
            dfs2(g, i, s, add);
        }
    }
}
