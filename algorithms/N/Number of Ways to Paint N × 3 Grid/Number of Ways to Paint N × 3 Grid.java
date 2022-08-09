class Solution {
    int MOD = 1000000007;
    int[][] states = {{0,1,0},{1,0,1},{2,0,1},
                      {0,1,2},{1,0,2},{2,0,2},
                      {0,2,0},{1,2,0},{2,1,0},
                      {0,2,1},{1,2,1},{2,1,2}};
    
    HashMap<Integer, List<Integer>> nextMap = new HashMap<>();
    Long[][] memo;
    
    public int numOfWays(int n) {
        if(n == 0)
            return 0;
        
		// Graph
        for(int prev = 0; prev < 12; prev++){
            List<Integer> nexts = new ArrayList<>();
            for(int next = 0; next < 12; next++){
                if(next == prev) continue;
            
                boolean flag = true;
                for(int i = 0; i < 3; i++){
                    if(states[prev][i] == states[next][i]){
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    nexts.add(next);
            }
            nextMap.put(prev, nexts);
        }
		
		//DFS
        memo = new Long[12][n];
        long ways = 0;
        for(int i = 0; i < 12; i++){
            ways += dfs(i, n-1);
            ways %= MOD;
        }
        
        return (int)(ways);
    }
    
    long dfs(int prev, int n){
        if(n == 0)
            return 1;
        
        if(memo[prev][n] != null)
            return memo[prev][n];
        
        long ways = 0;
        
        List<Integer> nexts = nextMap.get(prev);
        for(int next : nexts){
            ways += dfs(next, n-1);
            ways %= MOD;
        }
        
        memo[prev][n] = ways;
        return ways;
    }
}