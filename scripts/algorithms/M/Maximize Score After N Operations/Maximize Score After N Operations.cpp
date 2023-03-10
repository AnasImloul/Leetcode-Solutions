int dp[16384];
int gcd_table[14][14];

class Solution {
public:
    int maxScore(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sz = nums.size();

        // Build the GCD table 
        for (int i = 0; i < sz; ++i) {
            for (int j = i+1; j < sz; ++j) {gcd_table[i][j] = gcd(nums[i], nums[j]);}
        }

        // Looping from state 0 to (1<<sz)-1
        dp[0] = 0;
        for (int s = 0; s < (1<<sz); ++s) {
            int cnt = __builtin_popcount(s);
            if (cnt &1 )continue; // bitcount can't be odd
            for (int i = 0; i < sz; ++i) {
                if (s & (1<<i)) continue;
                for (int j = i+1; j < sz; ++j) {
                    if (s & (1<<j)) continue;
                    int next_state = s^(1<<i)^(1<<j);
                    dp[next_state] = max(dp[next_state], dp[s] + (cnt/2+1)*gcd_table[i][j]);
                }
            }
        }
        return dp[(1<<sz)-1];
    }
};