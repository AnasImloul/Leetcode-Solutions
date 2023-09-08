// Runtime: 1 ms (Top 90.5%) | Memory: 39.56 MB (Top 93.7%)

class Solution {
    public double soupServings(int n) {
        if(n>4800) return 1;
         n=(int)Math.ceil(n*1.0/25);
        double dp[][]= new double[n+1][n+1];
        return helper(n,n,dp);
    }
    double helper(int a,int b,double dp[][]){
        if(a<=0 && b<=0) return 0.5;
        if(b<=0) return 0;
        if(a<=0) return 1;
        if(dp[a][b]>0) return dp[a][b];
        return dp[a][b]=0.25*(helper(a-4,b,dp)+helper(a-3,b-1,dp)+helper(a-2,b-2,dp)+helper(a-1,b-3,dp));
    }
}
// Upvote please !!