// version 1 : O(mn) space
class Solution {
    public int countSubstrings(String s, String t) {
        int m = s.length(), n = t.length();

        int[][][] dp = new int[m][n][2];
        
        int res = 0;
        // first col s[0:i] match t[0:0]
        for (int i = 0; i < m; i++) {
            dp[i][0][0] = (s.charAt(i) == t.charAt(0)) ? 1 : 0;
            dp[i][0][1] = (s.charAt(i) == t.charAt(0)) ? 0 : 1;
            res += dp[i][0][1];
        }
      
        
        // first row s[0:0] match t[0:j]
        for (int j = 1; j < n; j++) {
            dp[0][j][0] = (s.charAt(0) == t.charAt(j)) ? 1 : 0;
            dp[0][j][1] = (s.charAt(0) == t.charAt(j)) ? 0 : 1;
            res += dp[0][j][1];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j][0] = (s.charAt(i) == t.charAt(j)) ? dp[i-1][j-1][0] + 1 : 0;
                dp[i][j][1] = (s.charAt(i) == t.charAt(j)) ? dp[i-1][j-1][1] : dp[i-1][j-1][0] + 1;
                res += dp[i][j][1];
            }
        }

        return res;
    }
}
