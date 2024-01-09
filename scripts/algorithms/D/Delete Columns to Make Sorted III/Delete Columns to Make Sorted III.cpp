// Runtime: 13 ms (Top 76.86%) | Memory: 10.60 MB (Top 44.63%)

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int n = strs.size();
        int m = strs[0].length();

        vector<int> dp(m, 1);
        int res = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < i; j++) {
                for(int k = 0; k <= n; k++) {
                    if(k == n) {
                        dp[i] = max(dp[i], dp[j] + 1);
                        res = max(res, dp[i]);
                    } else if (strs[k][j] > strs[k][i]) {
                        break;
                    }
                }
            }
        }
        return m - res;
    }
};
