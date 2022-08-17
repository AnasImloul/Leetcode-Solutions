class Solution {
    public boolean checkPartitioning(String s) {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        for(int g=0 ; g<n ; g++){
            for(int i=0, j=g ; j<n ; j++, i++){
                if(g == 0)
                    dp[i][j] = true;
                else if(g == 1)
                    dp[i][j] = (s.charAt(i) == s.charAt(j)) ? true : false;
                else{
                    dp[i][j] = (dp[i+1][j-1]&((s.charAt(i) == s.charAt(j)) ? true : false));
                }
            }
        }
        for(int i=0 ; i<n-2 ; i++){
             if(dp[0][i]){
                for(int j=i+1 ; j<n-1 ; j++){
                    if(dp[i+1][j] && dp[j+1][n-1]){
                        return true;
                    }
                }
             }
        }
        return false;
    }
}
