// Runtime: 10 ms (Top 20.79%) | Memory: 10.1 MB (Top 71.20%)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = -1;
        int first = nums[0];

        // check the array for rotated point when it is obtained break the loop and assign result as rotation point
        for(int i = 1; i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                result = nums[i];
                break;
            }
        }
        // if the array is not sorted return first element
        if(result == -1) {
            return first;
        }
        return result;
    }
};