// Runtime: 234 ms (Top 36.67%) | Memory: 42.3 MB (Top 94.92%)
class Solution {
    /*
    Make directed graph
    u -> v means, v is in the range of u
    check from which node maximum nodes can be reached and return the number of nodes reached
    */
    public int maximumDetonation(int[][] bombs) {
        Map<Integer, List<Integer>> graph = new HashMap<>();

        int n = bombs.length;
        for(int i = 0; i< n; i++){
            graph.put(i, new ArrayList<>());
            for(int j = 0; j< n; j++){
                if(i == j) continue;
                if(inRange(bombs[i], bombs[j]))
                    graph.get(i).add(j);
            }
        }

        int max = 0;
        for(int i = 0; i< n; i++){
            max = Math.max(max, dfs(i, graph, new HashSet<>()));
        }
        return max;
    }

    private boolean inRange(int[] u, int[] v){
        // (x-a)^2 + (y-b)^2 = R^2 -> point (a, b) is at border
        // (x-a)^2 + (y-b)^2 < R^2 -> point (a, b) is inside the circle
        // (x-a)^2 + (y-b)^2 > R^2 -> point (a, b) is outside the circle
        return Math.pow(u[0]-v[0], 2) + Math.pow(u[1]-v[1], 2) <= Math.pow(u[2], 2);
    }

    private int dfs(int node, Map<Integer, List<Integer>> graph, Set<Integer> visited){
        if(visited.contains(node)) return 0;
        visited.add(node);
        int res = 0;
        for(int neigh: graph.get(node)){
            res += dfs(neigh, graph, visited);
        }
        return res + 1;
    }
}