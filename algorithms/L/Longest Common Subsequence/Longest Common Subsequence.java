class Solution 
{
    public int longestCommonSubsequence(String text1, String text2)
    {
        // O(n * m) time | space
        int n = text1.length();
        int m = text2.length();
        
        // dp[i][j] represents that the length of longestCommonSubsequence at text1[i] && text[2]
        int[][] dp = new int[n+1][m+1];
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(text1.charAt(i) == text2.charAt(j))
                    dp[i+1][j+1] = 1 + dp[i][j];
                else
                    dp[i+1][j+1] = Math.max(dp[i][j+1], dp[i+1][j]);
            }
        }      
        return dp[n][m];
    }
}
