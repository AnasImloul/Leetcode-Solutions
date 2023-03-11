class Solution {
    public int getMoneyAmount(int n) {
        int dp[][]=new int[n+1][n+1];
        for(int a[]:dp){
            Arrays.fill(a,-1);
        }
        return solve(1,n,dp);
    }
    static int solve(int start,int end,int[][] dp){
    if(start>=end) return 0;
    if(dp[start][end]!=-1) return dp[start][end];
    int min=Integer.MAX_VALUE;
    for(int i=start;i<=end;i++){
    min=Math.min(min,i+Math.max(solve(start,i-1,dp),solve(i+1,end,dp)));
    }
    dp[start][end]=min;
    return min;
    }
}