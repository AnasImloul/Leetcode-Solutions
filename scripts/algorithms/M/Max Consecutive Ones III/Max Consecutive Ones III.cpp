class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        // max length of subarray with at most k zeroes 
    
        int i=0;
        int j=0;
        int cnt = 0;
        int ans = 0;

        int n = nums.size();

        while(j<n)
        {
            if(nums[j]==0)
                cnt++;

            if(cnt<=k)
            {
                ans = max(ans , j-i+1);
                j++;
            }
            else //cnt>k
            {
                while(cnt>k)
                {
                    if(nums[i]==0)
                        cnt--;
                    i++;
                }
                j++;
            }
        }
        return ans;
        
    }
};
