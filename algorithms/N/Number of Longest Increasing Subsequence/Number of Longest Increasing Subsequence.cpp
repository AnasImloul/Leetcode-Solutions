class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		int n = nums.size(), maxI=0, inc=0;
		vector<int> dp(n,1), count(n,1);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++){
				if(nums[i]>nums[j] && 1+dp[j] > dp[i])
				{
					dp[i] = 1+dp[j];
					count[i] = count[j];
				}
				else if(nums[i]>nums[j] && 1+dp[j] == dp[i])
					count[i] += count[j];
			}
			maxI = max(maxI, dp[i]);
		}
		for(int i=0;i<n;i++)
			if(maxI == dp[i])   inc += count[i];
		return inc;
	}
};