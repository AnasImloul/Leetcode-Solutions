class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        const int m = multipliers.size();
        const int n = nums.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1));
        for (auto z = 0; z < m; ++z) {
            int row{0};
            int col{z + 1};
            while (col >= 0) {
                dp[row][col] = max(
                    (row > 0 ? dp[row - 1][col] + nums[row - 1] * multipliers[z] : INT_MIN),
                    (col > 0 ? dp[row][col - 1] + nums[n - col] * multipliers[z] : INT_MIN));

                --col;
                ++row;
            }
        }

        auto maxScore = INT_MIN;
        for (auto row = 0; row <= m; ++row) {
            maxScore = max(maxScore, dp[row][m - row]);
        }

        return maxScore;
    }
};
