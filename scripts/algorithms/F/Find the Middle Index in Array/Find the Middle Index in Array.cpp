class Solution {
public:
  
    int findMiddleIndex(vector<int>& nums) 
    {
        int n=nums.size();
        int left_sum=0;
        int right_sum=0;
        for(int i=0;i<n;i++)
        {
            right_sum+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            right_sum-=nums[i];
            if(left_sum==right_sum)
            {
                return i;
            }
            left_sum+=nums[i];
        }
        return -1;
    }
};
