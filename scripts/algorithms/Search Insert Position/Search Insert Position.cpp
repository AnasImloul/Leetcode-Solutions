class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(target>nums[high])
            {
                return high+1;
            }
            else if(target<nums[mid])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};
