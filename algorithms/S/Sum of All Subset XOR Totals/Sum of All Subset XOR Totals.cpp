class Solution {
public:
    
    
    int subsetXORSum(vector<int>& nums) 
    {
        int ans=0;
        for(int i=0; i<32; i++)
        {
            int mask=1<<i;
            int count=0;
            for(int j=0; j<nums.size(); j++)
            {
                if(nums[j]&mask) count++;
            }
            if(count)
            {
                ans+=mask*(1<<(count-1))*(1<<(nums.size()-count));
            }
        }
        return ans;
    }
};
