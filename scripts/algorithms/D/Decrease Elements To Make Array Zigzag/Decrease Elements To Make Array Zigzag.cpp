// Runtime: 0 ms (Top 100.0%) | Memory: 7.50 MB (Top 80.85%)

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int even = 0, odd = 0;

		if (nums.size() <= 1) return 0;

        /* Even indices are smaller */
        for (int i = 0; i < nums.size(); i+= 2) {
			if (i == 0) {
				if (nums[i] >= nums[i+1]) even += nums[i]-nums[i+1]+1;
			} else if (i == nums.size() - 1) {
				if (nums[i-1] <= nums[i]) even += nums[i]-nums[i-1]+1;
			} else {
				if (nums[i-1] <= nums[i] || nums[i+1] <= nums[i]) {
					even += nums[i] - min(nums[i-1], nums[i+1]) + 1;
				}
			}
		}
        
        /* Odd indices are smaller */
		for (int i = 1; i < nums.size(); i += 2) {
			if (i == nums.size() - 1) {
				if (nums[i-1] <= nums[i]) odd += nums[i]-nums[i-1]+1;
			} else {
				if (nums[i-1] <= nums[i] || nums[i+1] <= nums[i]) {
					odd += nums[i] - min(nums[i-1], nums[i+1]) + 1;
				}
			}
		}

		return min(even, odd);
    }
};
