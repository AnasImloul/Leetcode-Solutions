// Runtime: 173 ms (Top 6.23%) | Memory: 61.5 MB (Top 69.24%)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int smallest = INT_MAX;
        int second_smallest = INT_MAX;
        for(int i = 0;i<n;i++)
        {
            if(nums[i] <= smallest)
            {
                smallest = nums[i];
            }
            else if(nums[i] <= second_smallest)
            {
                second_smallest = nums[i];
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};