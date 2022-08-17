/*
Approach :-> Given nums are from 0 to n-1 so to make local and global count equal  it must have swapping 
between adjacent element in sorted array so for any element at index if it is either swapped with i or i+1 or i-1 this is
only condition when both are equal else it got swapped with j > i+1 or j<i-1 then global count become greater 
than local count
*/
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==i || nums[i]==i-1 || nums[i]==i+1) continue;
            else return false;
        }
        return true;
    }
};
