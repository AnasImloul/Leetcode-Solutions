class Solution {
public:
	int solve(int i,vector<int>& nums,int target){
		if(i==nums.size()){
			if(target==0)return 1;
			return 0;
		} 
		int pick= solve(i+1,nums,target-nums[i]);
		int notpick= solve(i+1,nums,target+nums[i]);
		return pick+notpick;
	}

	int findTargetSumWays(vector<int>& nums, int target) {
		return solve(0,nums,target);  
	}
};