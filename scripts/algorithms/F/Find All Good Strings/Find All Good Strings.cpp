class Solution {
public:
    using ll = long long;
    int findGoodStrings(int n, string s1, string s2, string evil) {
      int M = 1e9+7;
      int m = evil.size();
      // kmp
      int f[m];
      f[0] = 0;
      for (int i = 1, j = 0; i < m; ++i) {
        while (j != 0 && evil[i] != evil[j]) {
          j = f[j-1];
        }
        if (evil[i] == evil[j]) {
          ++j;
        }
        f[i] = j;
      }
      // next(i,c) jump function when matched i length and see c
      int next[m+1][26];
      for (int i = 0; i <= m; ++i) {
        for (int j = 0; j < 26; ++j) {
          if (i < m && evil[i] == 'a'+j) {
            next[i][j] = i+1;
          } else {
            next[i][j] = i == 0? 0: next[f[i-1]][j];
          }
        }
      }
      // dp(i,j,l1,l2) length i greater than s1, less than s2;
      // match j length of evil
      // l1 true means limited for s1, l2 true means limited for s2
      ll dp[n+1][m+1][2][2];
      memset(dp, 0, sizeof(dp));
      dp[0][0][1][1] = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          for (int c = 0; c < 26; ++c) {
            int k = next[j][c];
            char ch = 'a'+c;
            dp[i+1][k][0][0] += dp[i][j][0][0];
            if (dp[i][j][1][1]) {
              if (ch > s1[i] && ch < s2[i]) {
                dp[i+1][k][0][0] += dp[i][j][1][1];
              } else if (ch == s1[i] && ch == s2[i]) {
                dp[i+1][k][1][1] += dp[i][j][1][1];
              } else if (ch == s1[i]) {
                dp[i+1][k][1][0] += dp[i][j][1][1];
              } else if (ch == s2[i]) {
                dp[i+1][k][0][1] += dp[i][j][1][1];
              }
            }
            if (dp[i][j][1][0]) {
              if (ch > s1[i]) {
                dp[i+1][k][0][0] += dp[i][j][1][0];
              } else if (ch == s1[i]) {
                dp[i+1][k][1][0] += dp[i][j][1][0];
              }
            }
            if (dp[i][j][0][1]) {
              if (ch < s2[i]) {
                dp[i+1][k][0][0] += dp[i][j][0][1];
              } else if (ch == s2[i]) {
                dp[i+1][k][0][1] += dp[i][j][0][1];
              }
            }
            dp[i+1][k][0][0] %= M;
          }
        }
      }
      ll ans = 0;
      for (int i = 0; i < m; ++i) {
        ans += dp[n][i][0][0] + dp[n][i][0][1] + dp[n][i][1][0];
        ans %= M;
      }
      return ans;
    }
};