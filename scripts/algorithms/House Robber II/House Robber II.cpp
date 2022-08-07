
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();  
        if(n == 1)
        {
            return nums[0];
        }
        //dp[n][2][1]
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(2, -1)));
        
        int maxm = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                for(int k = 0; k < 2; k++)
                {
                    maxm = max(maxm, dp_fun(dp, i, j, k, nums));
                }
            }
        }
        
        return maxm;
        
    }
    
    int dp_fun(vector<vector<vector<int>>> &dp, int ind, int num, int last, vector<int> &ar)
    {
        int n = ar.size();
        if(dp[ind][num][last] == -1)
        {
            if(ind == 0)
            {
                if(last == 1)
                {
                    dp[ind][num][last] = 0;
                }
                else 
                {
                    if(num == 1)
                    {
                        dp[ind][num][last] = ar[ind];
                    }
                    else 
                    {
                        dp[ind][num][last] = 0;
                    }
                }
            }
            else if (ind == n-1)
            {
                if(num == 0)
                {
                    dp[ind][num][last] = 0;
                }
                else 
                {
                    if(last == 0)
                    {
                        dp[ind][num][last] = dp_fun(dp, ind-1, 1, 0, ar);    
                    }
                    else 
                    {
                        dp[ind][num][last] = ar[ind] + dp_fun(dp, ind-1, 0, 1, ar);
                    }
                }
            }
            else 
            {
                if(num == 1)
                {
                    dp[ind][num][last] = max(ar[ind] + dp_fun(dp, ind-1, 0, last, ar), dp_fun(dp, ind-1, 1, last, ar));
                }
                else 
                {
                    dp[ind][num][last] = dp_fun(dp, ind-1, 1, last, ar);
                }
            }
        }
        return dp[ind][num][last];
    }
};