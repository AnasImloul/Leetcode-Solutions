// Runtime: 14 ms (Top 41.00%) | Memory: 13.8 MB (Top 71.46%)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int negPro = 1;
        int posPro = 1;
        int CHECK_ZERO = 0;
        int res = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                posPro = 1;
                negPro = 1;
                CHECK_ZERO = 1;
            }
            int numPos = posPro * nums[i];
            int numNeg = negPro * nums[i];
            posPro = max(numPos, max(numNeg, nums[i]));
            negPro = min(numPos, min(numNeg, nums[i]));
            res = max(posPro,res);
        }
        return (CHECK_ZERO ? max(0,res) : res);
    }
};