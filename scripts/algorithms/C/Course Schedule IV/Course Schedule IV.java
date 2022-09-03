// Runtime: 1518 ms (Top 5.07%) | Memory: 118.7 MB (Top 6.29%)
class Solution {
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        // Generating Map
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for(int e[]: prerequisites){
            graph.putIfAbsent(e[0], new ArrayList<>());
            graph.get(e[0]).add(e[1]);
        }

        List<Boolean> list = new ArrayList<>();
        // Appling DFS for every query to get result
        for(int[] q: queries){
            list.add(isPre(q[0], q[1], graph, new HashSet<>()));
        }
        return list;
    }
    // Check if src comes before dst using DFS
    private boolean isPre(int src, int dst, Map<Integer, List<Integer>> adj, Set<Integer> visited){
        if(visited.contains(src)) return false;
        visited.add(src);
        for(int neigh: adj.getOrDefault(src, new ArrayList<>())){
            if(neigh == dst || isPre(neigh, dst, adj, visited)) return true;
        }
        return false;
    }
}