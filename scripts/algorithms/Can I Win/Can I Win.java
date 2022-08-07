class Solution {
    int numlimit, tgt;
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        numlimit = maxChoosableInteger;
        tgt = desiredTotal;
        
        int maxsum = (numlimit*(numlimit+1))/2;
        if(maxsum < tgt)
            return false;
        
        int dp[] = new int[(1<<numlimit)];
        if(solve(0, 0, 0, dp)){
            return true;
        }
        return false;
    }
    
    public boolean solve(int mask, int lstsum, int player, int dp[]) {
        
        if(dp[mask] != 0)
            return (dp[mask] == 1);
        
        for(int i = 0; i < numlimit; i++) {
            if((mask&(1<<i)) == 0) {
                if((lstsum+(i+1) >= tgt) || !solve((mask|(1<<i)), lstsum+(i+1), player+1, dp)) {
                    dp[mask] = 1;
                    return true;
                } 
            }
        }
        
        dp[mask] = -1;
        return false;
    }
}
