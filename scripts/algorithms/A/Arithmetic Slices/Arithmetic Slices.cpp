class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(),i,j,count=0,comm_diff;
        for(i=0;i<=n-3;i++)
        {
            comm_diff = nums[i+1]-nums[i];
            for(j=i+1;j<n;j++)
            {
                if(nums[j]-nums[j-1]==comm_diff)
                {
                    if((j-i+1)>=3)
                    {
                        count++;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return count;
    }
};