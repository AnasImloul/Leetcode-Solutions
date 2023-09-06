// Runtime: 19 ms (Top 47.6%) | Memory: 43.93 MB (Top 22.2%)

class Solution {
    public int coinChange(int[] coins, int amount) {
        int m=coins.length,n=amount;
        int dp[][]=new int[m+1][n+1];
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        }
          for(int i=0;i<=m;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
               int t1 = Integer.MAX_VALUE;
        if ((i-1) == 0) {
            if (j % coins[i-1] == 0) {
                dp[i][j]= j / coins[i-1];
            } else {
                dp[i][j]= (int)1e9;
            }
        } 
        else {
            int t2 = dp[i-1][j];
        if (coins[i-1] <= j) {
            t1 = dp[i][j-coins[i-1]] + 1; 
        }
                dp[i][j]= Math.min(t1, t2);
        }
            }
        }
          if(dp[m][n]>=1e9)
        return -1;
        else
        return dp[m][n];
        }
    }
    
  