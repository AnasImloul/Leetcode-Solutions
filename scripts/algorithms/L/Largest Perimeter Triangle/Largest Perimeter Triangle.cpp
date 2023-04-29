class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
	// sort the elements 
        sort(nums.begin(),nums.end());
		// iterate in everse order to get maximum perimeter
        for (int i=nums.size()-2; i>=1 ; i--){
		//Triangle is formed if sum of two sides is greater than third side
        if (nums[i]+nums[i-1] >nums[i+1])return (nums[i]+nums[i+1]+nums[i-1]); // return perimeter which is sum of three sides
        }
        return 0; // when no triangle possible it will come out of loop so return 0 here
        
    }
};