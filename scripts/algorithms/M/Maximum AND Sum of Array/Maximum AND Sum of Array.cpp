class Solution {
private:
    int dp[20][60000];
    vector<int> a;
    int n;
    int k;
    // n numbers, k slots
    int ans;
    int h[12];  // h[i] == 3^i
    int search(int start, int mask) {
        if (start == n) return 0;
        if (dp[start][mask] != -1) return dp[start][mask];
        // try to push a[start] into slot 1 ~ k
        for (int i = 1; i <= k; i++) {
            int cnt = (mask % h[i+1]) / h[i];
            if (cnt <= 1) {
                dp[start][mask] = max(dp[start][mask], (a[start] & i) + search(start+1, mask + h[i]));
            }
        }
        return dp[start][mask];
    }
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        // states: at most 3^k
        // search: k
        a.assign(nums.begin(), nums.end());
        memset(dp, -1, sizeof(dp));
        // dp[i][mask]: the answer for nums[i:] with mask   (based-3)
        // a 3^1 + b 3^2 + c 3^3 + ...
        n = nums.size();
        k = numSlots;
        ans = 0;
        h[0] = 1;
        for (int i = 1; i < 12; i++)
			h[i] = h[i-1] * 3;
        return search(0, 0);
    }
};
