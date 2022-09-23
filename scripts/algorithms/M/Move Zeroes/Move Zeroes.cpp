// Runtime: 47 ms (Top 39.17%) | Memory: 19.3 MB (Top 13.84%)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nums_size = nums.size();
        int cntr=0;

        for(int i=0;i<nums_size;i++)
        {
            if(nums[i] != 0)
            {
                nums[cntr] = nums[i];
                cntr++;
            }
        }
        for( int i=cntr;i<nums_size;i++)
        {
            nums[i] = 0;
        }
    }
};