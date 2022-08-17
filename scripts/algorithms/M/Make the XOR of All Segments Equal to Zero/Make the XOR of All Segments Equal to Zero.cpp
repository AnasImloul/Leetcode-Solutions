class Solution {
   public:
    int minChanges(vector<int>& nums, int k) {
        const auto n = nums.size();
        const int limit =
            1 << static_cast<int>(
                ceil(log2(*max_element(nums.cbegin(), nums.cend()) + 1)));

        vector<unordered_map<int, int>> freq(k);
        for (int i = 0; i != n; ++i) {
            ++freq[i % k][nums[i]];
        }

        vector<int> dp(limit);
        vector<int> tmpdp(limit);
        int last_min = numeric_limits<int>::max();

        for (int j = 0; j != limit; ++j) {
            dp[j] = n / k + (n % k > 0) - freq[0][j];
            last_min = min(last_min, dp[j]);
        }

        for (int i = 1; i != k; ++i) {
            int cnt = n / k + (n % k > i);
            int new_min = numeric_limits<int>::max();
            for (int j = 0; j != limit; ++j) {
                int mi = numeric_limits<int>::max();
                for (auto& [v, f] : freq[i]) {
                    mi = min(mi, dp[j ^ v] - f);
                }
                mi = min(mi, last_min);

                mi += cnt;
                new_min = min(new_min, mi);
                tmpdp[j] = mi;
            }
            last_min = new_min;
            swap(tmpdp, dp);
        }

        return dp[0];
    }
};
