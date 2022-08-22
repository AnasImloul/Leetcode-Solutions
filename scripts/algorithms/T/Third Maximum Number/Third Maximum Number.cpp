// Runtime: 3 ms (Top 97.89%) | Memory: 9 MB (Top 96.12%)
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int c=0;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]!=nums[i+1])
            {
                c=c+1;
            }
            if(c==2)
            {
                return nums[i];
                break;
            }
        }
        return nums[n-1];
    }
};