class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int totalASC = 0;
        for (int i = 0; i < m; i++) {
            totalASC += s1[i];
        }
        for (int j = 0; j < n; j++) {
            totalASC += s2[j];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + s1[i - 1] + s2[j - 1];
                    
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return totalASC - dp[m][n];
    }
};
