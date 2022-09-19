// Runtime: 10 ms (Top 13.89%) | Memory: 41.7 MB (Top 61.06%)
class Solution {
    int solve(int[] v, int i, int j){
        if(i+1==j)
            return 0;
        int ans= Integer.MAX_VALUE;
        for(int k=i+1;k<j;k++){
            ans= Math.min(ans, (v[i]*v[j]*v[k] + solve(v,i,k) + solve(v,k,j) ) );
        }
        return ans;
    }

    int solveMem(int[] v, int i, int j, int[][] dp){
      if(i+1==j)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

       int ans= Integer.MAX_VALUE;

        for(int k=i+1;k<j;k++){
          ans = Math.min(ans, (v[i]*v[j]*v[k] + solveMem(v,i,k,dp) + solveMem(v,k,j,dp) ) );
        }
        dp[i][j]=ans;
        return dp[i][j];
    }

    int solveTab(int[] v){
        int n= v.length;
        int[][] dp= new int[n][n];

        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n;j++){

                int ans=Integer.MAX_VALUE;
                 for(int k=i+1;k<j;k++){
                    ans = Math.min(ans, (v[i]*v[j]*v[k] + dp[i][k] + dp[k][j] ) );
                    }
                    dp[i][j]=ans;
            }
        }

        return dp[0][n-1];

        }

    public int minScoreTriangulation(int[] values) {
        int n= values.length;
       // return solve(values, 0, n-1); // For Recursion

    /* int[][] dp= new int[n][n]; // For Top-Down DP(Memoisation)
        for(int[] row:dp){
            Arrays.fill(row,-1);
        }

        return solveMem(values,0,n-1,dp);
        */

        return solveTab(values); //For Bottom-Down DP(Tabulisation)
    }
}