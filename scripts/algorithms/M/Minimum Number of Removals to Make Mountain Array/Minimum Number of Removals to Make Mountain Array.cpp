// Runtime: 862 ms (Top 5.02%) | Memory: 12.1 MB (Top 84.66%)
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp1(n,1), dp2(n,1);

        // LIS from front
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i] > nums[j] && 1 + dp1[j] > dp1[i])
                {
                    dp1[i] = 1 + dp1[j];
                }
            }
        }

        //LIS from back
        for(int i=n-1; i>=0; i--)
        {
            for(int j=n-1; j>i; j--)
            {
                if(nums[i] > nums[j] && dp2[j] + 1 > dp2[i]){
                    dp2[i] = dp2[j] + 1;
                }
            }
        }

        int maxi = 1;
        for(int i=0; i<n; i++){
            if(dp1[i] > 1 && dp2[i] > 1){
                maxi = max(maxi, dp1[i] + dp2[i] -1);
            }
        }
        return (n-maxi);
    }
};
