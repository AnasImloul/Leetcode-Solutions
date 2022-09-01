// Runtime: 69 ms (Top 40.88%) | Memory: 13.2 MB (Top 27.46%)
class Solution
{
    public:

        const int NEG_INF = -10e8;
        int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        // NOTE : we can't initialize with INT_MIN because adding any val with it will give overflow
        // that is why we prefer 10^7 or 10^8

        vector<vector<int>> dp(n+1, vector<int>(m+1, NEG_INF));

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {

                int temp_p = nums1[i-1]*nums2[j-1];

        // Although it is a variation of LCS but here we need to check for all answers we already know in dp
        // Why only temp_p ? -> suppose in dp[i-1][j-1] is -10^7 + temp_p is 2 == gives nearly -10^7(which is wrong ans)
        // For Remaining comparisons we already know why !

                dp[i][j] = max({ dp[i-1][j-1] + temp_p,
                                      temp_p,
                                      dp[i-1][j],
                                      dp[i][j-1]
                              });
            }
        }

        return dp[n][m];
    }
};