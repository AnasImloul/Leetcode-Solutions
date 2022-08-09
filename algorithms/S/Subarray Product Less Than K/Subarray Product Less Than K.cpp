class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {

		int i = 0, j = 0, n = nums.size(); 
		long pro = 1;
		int cnt = 0;

		while(j < n){

			pro *= nums[j];
			while(pro >= k and i <= j){
				pro /= nums[i];
				i++;   
			}
			cnt += j-i+1;
			j++;

		}
		return cnt;
	}
};

// upvote if it helps.