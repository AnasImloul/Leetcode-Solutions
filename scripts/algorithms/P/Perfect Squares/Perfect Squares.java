// Runtime: 20 ms (Top 91.34%) | Memory: 42.30 MB (Top 82.04%)

class Solution {
    public int numSquares(int n) {
        int dp[]=new int [n+1];
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2;i<dp.length;i++){
            int min=Integer.MAX_VALUE;
            for(int j=1;j*j<=i;j++){
                min=Math.min(min,dp[i-j*j]);
            }
            dp[i]=min+1;
        }
        return dp[n];
    }
}
