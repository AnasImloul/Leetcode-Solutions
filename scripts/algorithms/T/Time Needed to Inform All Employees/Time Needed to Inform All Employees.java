// Runtime: 89 ms (Top 45.5%) | Memory: 63.76 MB (Top 32.3%)

class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for(int i=0; i<n; i++) {
            graph.putIfAbsent(manager[i], new ArrayList<>());
            graph.get(manager[i]).add(i);
        }
        return dfs(graph, headID, informTime);
    }

    int dfs(Map<Integer, List<Integer>> graph, int curHead, int[] informTime) {
        int curMax = 0;
        if(!graph.containsKey(curHead)){
            return curMax;
        }
        for(int subordinate : graph.get(curHead)) {
            curMax = Math.max(curMax, dfs(graph, subordinate, informTime));
        }
        return curMax + informTime[curHead];
    }
}