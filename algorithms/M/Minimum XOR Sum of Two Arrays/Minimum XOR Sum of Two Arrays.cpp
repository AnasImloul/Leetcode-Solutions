class Solution {
public:
    int dp[14][16384];
    int dfs(vector<int> &nums1, vector<int> &nums2, int used, int i) {
        if (i == nums1.size())
            return 0;
			
        if (dp[i][used] > -1)
            return dp[i][used];
        int small = INT_MAX;
        for (int j = 0; j < nums2.size(); j++) {
            if (!(used & (1 << j))) {
                small = min(small, (nums1[i] xor nums2[j]) + dfs(nums1, nums2, used | (1 << j), i + 1));
            }
        }
        return dp[i][used] = small;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {    
        memset(dp, -1, sizeof(dp));
        return dfs(nums1, nums2, 0, 0);
    }
};
