class Solution {
public:
    int max_value = 1000000;
    int min_value = -1000000;
    
    int findUnsortedSubarray(vector<int>& nums) {
		// max_list refers to: the max value on the left side of the current element
		// min_list refers to: the min value on the right side of the current element
        vector<int> max_list(nums.size(), 0);
        vector<int> min_list(nums.size(), 0);
        min_list[nums.size()-1] = max_value;
        max_list[0] = min_value;
        
        // init two lists
        for(int i=nums.size()-2; i>=0; i--)
            min_list[i] = min(min_list[i+1], nums[i+1]);
        
        for(int i=1; i<nums.size(); i++) 
            max_list[i] = max(max_list[i-1], nums[i-1]);
        
        // get left bound
        int left = 0;
        while(left < nums.size() && min_list[left] >= nums[left])
            left++;
        
        // get right bound
        int right = nums.size() - 1;
        while(right >= 0 && max_list[right] <= nums[right])
            right--;
        
        if (left == nums.size()) // monotonic ascending array
            return 0;
        else
            return (right-left+1);
    }
};
