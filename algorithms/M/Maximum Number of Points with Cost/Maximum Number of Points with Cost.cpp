class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<vector<long long>> dp(points.size(), vector<long long>(points[0].size(), -1));
        
        for (int i = 0; i < points[0].size(); ++i) {
            dp[0][i] = points[0][i];
        }
        
        for (int i = 1; i < points.size(); ++i) {
            for (int j = 0; j < points[i].size(); ++j) {
                for (int k = 0; k < points[i].size(); ++k) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] - abs(k - j) + points[i][j]);
                }
            }
        }
        
        long long max_ans = -1;
        for (const auto v : dp.back()) {
            max_ans = max(max_ans, v);
        }
        
        return max_ans;
    }
};
