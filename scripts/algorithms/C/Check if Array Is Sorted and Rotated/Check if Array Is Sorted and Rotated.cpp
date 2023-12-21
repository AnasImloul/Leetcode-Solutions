// Runtime: 4 ms (Top 32.48%) | Memory: 9.00 MB (Top 12.17%)

class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%nums.size()])
                count++;
        }
        return (count<=1);
    }
};
