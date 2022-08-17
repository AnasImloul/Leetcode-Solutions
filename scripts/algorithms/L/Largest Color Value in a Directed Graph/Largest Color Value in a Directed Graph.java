class Solution {
    private int max;
    private Map<Integer, Map<Character, Integer>> memo;
    private boolean hasCycle;
    
    public int largestPathValue(String colors, int[][] edges) {        
        Map<Integer, List<Integer>> map = new HashMap<>();
        
        for(int edge[] : edges) {
            List<Integer> list = map.getOrDefault(edge[0], new ArrayList<>());
            list.add(edge[1]);
            map.put(edge[0], list);
        }
        
        max = -1;
        memo = new HashMap<>();
        
        boolean visited[] = new boolean[colors.length()];
        hasCycle = false;
        
        for(int i = 0; i < colors.length(); i++) {
            dfs(i, map, colors, visited);
            
            if(hasCycle) {
                return -1;
            }
        }
        
        return max;
    }
    
    private Map<Character, Integer> dfs(int curr, Map<Integer, List<Integer>> map, String colors, boolean visited[]) {
        if(visited[curr]) {
            hasCycle = true;
            return new HashMap<>();
        }
        
        if(memo.get(curr) != null) {
            return memo.get(curr);
        }
        
        visited[curr] = true;
        List<Integer> list = map.get(curr);
        Map<Character, Integer> currMap = new HashMap<>();
                
        if(list != null && !list.isEmpty()) {
            for(int i : list) {
                Map<Character, Integer> resMap = dfs(i, map, colors, visited);
                
                if(hasCycle) {
                    return currMap;
                }
                
                for(char c : resMap.keySet()) {
                    int val = resMap.get(c);
                    int currVal = currMap.getOrDefault(c, 0);
                    currVal = Math.max(currVal, val);
                    currMap.put(c, currVal);
                    max = Math.max(currVal, max);
                }
            }
        }
        
        int currentNodeColorCount = currMap.getOrDefault(colors.charAt(curr), 0);
        currMap.put(colors.charAt(curr), currentNodeColorCount + 1);
        
        max = Math.max(currentNodeColorCount + 1, max);
        
        visited[curr] = false;
        memo.put(curr, currMap);
        return currMap;
    }
}