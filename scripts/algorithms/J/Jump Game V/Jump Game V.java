class Solution {
    public int maxJumps(int[] arr, int d) {
        int n = arr.length;
        
        Map<Integer, List<Integer>> graph = new HashMap<>();
        
        for(int i = 0; i< n; i++){
            Set<Integer> visited = new HashSet<>();
            //Starting from i-1 and going towards 0 is important as some element in between may exist we breaks the loop
            //if we start form Math.max(i-d, 0) if loop breaks we will have element will don't satisfy the condition that all element
            //between i-d and i-1 are smaller the arr[i] to be added in graph
            for(int j = i-1; j >= Math.max(i-d, 0); j--){
                if(arr[j]>=arr[i]) break;
                graph.putIfAbsent(i, new ArrayList<Integer>());
                graph.get(i).add(j);
                visited.add(j);
            }
            for(int j = i+1; j<=Math.min(i+d, n-1); j++){
                if(arr[j]>=arr[i]) break;
                graph.putIfAbsent(i, new ArrayList<Integer>());
                graph.get(i).add(j);
                visited.add(j);
            }
        }
        int max = 0;
        int[] memo = new int[n];
        Arrays.fill(memo, -1);
        for(int i = 0; i < n; i++){
            max = Math.max(max, dfs(i, graph, memo, new HashSet<>()));
        }
        return max;
    }
    private int dfs(int ptr, Map<Integer, List<Integer>> graph, int[] memo, Set<Integer> visited){
        if(memo[ptr]!=-1) return memo[ptr];
        visited.add(ptr);
        int res = 0;
        for(int index: graph.getOrDefault(ptr, new ArrayList<>())){
            if(visited.contains(index)) continue;
            res = Math.max(res, dfs(index, graph, memo, visited));
        }
        visited.remove(ptr);
        return memo[ptr] = res+1;
    }
}
