class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        long long int num=0;
        
        int ans=1;
        
        int start=0;
        int end=0;
        
        while(end<nums.size())
        {
            //checking if the curr num can be taken or not
            if(start==end)
            {
            num = num ^ nums[end];
            end++;	
            }
            else if((num & (nums[end])) > 0)
            {
                num = num ^ nums[start];
                start++;
            }
            else if((num & (nums[end])) ==0)
            {
                ans = max(ans,(end-start+1));
                num = num ^ nums[end];
                end++;
            }
            
        }
        return ans;
    }
};