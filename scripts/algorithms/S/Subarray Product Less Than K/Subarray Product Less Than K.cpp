// Runtime: 138 ms (Top 5.04%) | Memory: 61.50 MB (Top 67.87%)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, prod = 1, j = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && i <= j) 
                prod =  prod/nums[i-1];
            else 
                j = i;
            while (j < n &&  prod*nums[j] < k) prod *= nums[j++];
            ans += j-i;
        }
        return ans;
    }
};
