// Runtime: 1285 ms (Top 5.12%) | Memory: 94.10 MB (Top 5.12%)

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size(), N = 1000000;
        vector<int> cnt(N, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) 
                cnt[abs(nums[i]-nums[j])]++;
        }
        for (int i = 0; i < N; i++) {
            if (cnt[i] >= k) return i;
            k -= cnt[i];
        }
        return 0;
    }
};
