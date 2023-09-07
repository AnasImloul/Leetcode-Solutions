// Runtime: 83 ms (Top 5.5%) | Memory: 43.82 MB (Top 67.0%)

class Solution {
    public int countCompleteComponents(int n, int[][] edges) {
       int[] parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }    
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int parentU = find(parent, u);
            int parentV = find(parent, v);
            if (parentU != parentV) {
                parent[parentV] = parentU;
            }
        }  
        Map<Integer, Set<Integer>> groups = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int group = find(parent, i);
            groups.computeIfAbsent(group, k -> new HashSet<>()).add(i);
        }
        
        int count = 0;
        for (Set<Integer> group : groups.values()) {
            boolean isComplete = true;
            for (int i : group) {
                for (int j : group) {
                    if (i != j && !hasEdge(edges, i, j)) {
                        isComplete = false;
                        break;
                    }
                }
                if (!isComplete) {
                    break;
                }
            }
            if (isComplete) {
                count++;
            }
        }    
        return count;
    }
    private int find(int[] parent, int node) {
        if (parent[node] != node) {
            parent[node] = find(parent, parent[node]);
        }
        return parent[node];
    }
    
    private boolean hasEdge(int[][] edges, int u, int v) {
        for (int[] edge : edges) {
            if ((edge[0] == u && edge[1] == v) || (edge[0] == v && edge[1] == u)) {
                return true;
            }
        }
        return false;
    }
}