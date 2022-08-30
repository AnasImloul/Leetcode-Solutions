// Runtime: 111 ms (Top 80.62%) | Memory: 10.8 MB (Top 79.38%)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        int res = 1;
        for(int j = 1; j < n; j++){
            for(int r = 0, c = j ; r < n && c < n; r++, c++){
                if(s[r] == s[c]){
                    dp[r][c] = 2+dp[r+1][c-1];
                }
                else{
                    dp[r][c] = max(dp[r][c-1],dp[r+1][c]);
                }
            }
        }
        return dp[0][n-1];
    }
};