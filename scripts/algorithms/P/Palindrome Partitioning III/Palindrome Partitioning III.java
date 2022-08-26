// Runtime: 38 ms (Top 26.09%) | Memory: 55.8 MB (Top 6.28%)
class Solution {
    public int mismatchCount(String s) {
        int n = s.length()-1;
        int count = 0;
        for(int i=0,j=n;i<j;i++,j--) {
            if(s.charAt(i) != s.charAt(j))
                count++;
        }
        return count;
    }
    public int helper(String s, int n, int i, int j, int k, Integer[][][] dp) {
        if(j>=n)
            return 105;
        if(k<0)
            return 105;
        if(dp[i][j][k] != null) {
            return dp[i][j][k];
        }
        if(n-j<k)
            return dp[i][j][k] = 105;
        if(n-j==k)
            return dp[i][j][k] = mismatchCount(s.substring(i,j+1));
        int stop = mismatchCount(s.substring(i,j+1)) + helper(s,n,j+1,j+1,k-1,dp);
        int cont = helper(s,n,i,j+1,k,dp);
        return dp[i][j][k] = Math.min(stop, cont);
    }
    public int palindromePartition(String s, int k) {
        int n = s.length();
        Integer[][][] dp = new Integer[n][n][k+1];
        return helper(s,s.length(),0,0,k,dp);
    }
}