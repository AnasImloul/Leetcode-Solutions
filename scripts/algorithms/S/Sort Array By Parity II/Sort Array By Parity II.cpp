// Runtime: 28 ms (Top 76.96%) | Memory: 21.4 MB (Top 66.53%)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {

        vector<int>ans(nums.size());

        int even_idx=0;
        int odd_idx=1;

        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]%2)==0) //the num is even
            {
                ans[even_idx]=nums[i];
                even_idx+=2;
            }
            else //the num is odd
            {
                ans[odd_idx]=nums[i];
                odd_idx+=2;
            }
        }
        return ans;
    }
};