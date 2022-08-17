class Solution {
    public int[] smallestMissingValueSubtree(int[] parents, int[] nums) {
        int n = parents.length;
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = 1;
        }
        
        int oneIndex = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                oneIndex = i;
                break;
            }
        }
        
        // 1 not found
        if (oneIndex == -1) {
            return res;
        }
        
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        for (int i = 1; i < n; i++) {
            Set<Integer> children = graph.getOrDefault(parents[i], new HashSet<Integer>());
            children.add(i);
            graph.put(parents[i], children);
        }
        
        Set<Integer> visited = new HashSet<Integer>();
        
        int parentIter = oneIndex;
        int miss = 1;
        while (parentIter >= 0) {
            dfs(parentIter, graph, visited, nums);
            while (visited.contains(miss)) {
                miss++;
            }
            res[parentIter] = miss;
            parentIter = parents[parentIter];
        }
        return res;
    }
    
    public void dfs(int ind, Map<Integer, Set<Integer>> graph, Set<Integer> visited, int []nums) {
        if (!visited.contains(nums[ind])) {
            Set <Integer> children = graph.getOrDefault(ind, new HashSet<Integer>());
        
            for (int p : children) {
                dfs(p, graph, visited, nums);
            }
            visited.add(nums[ind]);
        }
    }
}
