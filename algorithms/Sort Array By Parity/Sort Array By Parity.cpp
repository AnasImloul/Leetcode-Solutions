class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
        {
            return nums;
        }
        
        int j = n - 1;
        for (int i = 0; i < j; i ++)
        {
            while(j > i)
            {
                if (nums[j] % 2 == 0)
                {
                    break;
                }
                j --;
            }
            
            if (nums[i] % 2)
            {
                swap(nums[i], nums[j]);
            }
        }
        
        return nums;
    }
};
