class Solution {
    
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        int dp[][] = new int[m][n];
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                dp[i][j] = -1;
            }
        }
        return solve(word1, word2 , m-1, n-1 ,dp);
    }
    
    public int solve(String str1, String str2, int m , int  n , int dp[][]){
        if(m<0){
            return n+1;
        }
        if(n<0){
            return m+1;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        if(str1.charAt(m) == str2.charAt(n)){
            return solve(str1, str2 , m-1, n-1 ,dp);
        }
        else{
            int min = Math.min(solve(str1, str2, m-1 ,n ,dp), solve(str1, str2, m ,n-1 , dp));
            dp[m][n] = 1+Math.min(min, solve(str1, str2, m-1, n-1, dp));
        }
        return dp[m][n];
    }
}
