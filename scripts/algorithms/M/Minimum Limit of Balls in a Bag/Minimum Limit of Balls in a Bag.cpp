// Runtime: 412 ms (Top 28.34%) | Memory: 56 MB (Top 33.00%)
class Solution {
public:
    bool isPossible(vector<int>&nums,int mid_penalty,int maxOperations)
    {
        int operations=0;

        for(int i=0;i<nums.size();i++)
        {
            operations+=(nums[i]/mid_penalty); //Operations Nedded to divide that element.
            if(nums[i]%mid_penalty==0) //if it is completely divisible means less 1 less is needed for that nums.
                operations--;
        }

        return operations<=maxOperations?1:0; //If operations are less than maxOperations it is one of our ans.
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low_penalty=1,high_penalty=*max_element(nums.begin(),nums.end());
        int ans=high_penalty;
        while(low_penalty<=high_penalty)
        {
            int mid_penalty=low_penalty+(high_penalty-low_penalty)/2;
            if(mid_penalty==0) //To avoid divison by zero.
                break;
            if(isPossible(nums,mid_penalty,maxOperations))
            {
                ans=mid_penalty;
                high_penalty=mid_penalty-1;
            }
            else
                low_penalty=mid_penalty+1;
        }
        return ans;
    }
};