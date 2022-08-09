class Solution {

public int strangePrinter(String s) {
    if (s.equals("")) return 0;
    int len = s.length();
    int[][] dp = new int[len][len];
    for (int i = 0; i < len; i++)
        dp[i][i] = 1;
    for (int l = 2; l <= len; l++) {
        for (int i = 0; i < len && l + i - 1 < len; i++) {
            int j = l + i - 1;
            dp[i][j] = dp[i][j - 1] + (s.charAt(i) == s.charAt(j) ? 0 : 1);
            for (int k = i + 1; k < j; k++) {
                if (s.charAt(k) == s.charAt(j)) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k - 1] + dp[k][j - 1]);
                }
            }
        }
    }
    return dp[0][len - 1];
}
}