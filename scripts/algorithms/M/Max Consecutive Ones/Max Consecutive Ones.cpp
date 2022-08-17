class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int curr_count = 0;
        int max_count = 0;
        int i = 0;
        while(i < nums.size())
        {
            if(nums[i] == 1)
            {
                curr_count += 1;
                if(max_count < curr_count)
                    max_count = curr_count;                        
            }
            
            else
                curr_count = 0;
            i++;
        }
        return max_count;
    }
};
