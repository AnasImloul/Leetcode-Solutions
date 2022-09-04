// Runtime: 633 ms (Top 77.58%) | Memory: 145.9 MB (Top 23.71%)
class Solution {
public:

    int help(int i,int j, unordered_map<int,int> &mp,vector<int> &nums , vector<vector<int>> &dp){

        if(dp[i][j]!=-1)
            return dp[i][j];

        int x=nums[i]+nums[j];

        if(mp.find(x)!=mp.end())
        {
            dp[i][j]=help(j,mp[x],mp,nums,dp);
           return 1+dp[i][j];
        }

        return 1;
    }

   int solve(int idx ,int n, unordered_map<int,int> &mp,vector<int> &nums , vector<vector<int>> &dp)
    {
        int maxi=INT_MIN;

        for(int i=idx;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {

                int x=nums[i]+nums[j];

                if(mp.find(x)!=mp.end())
                {
                 maxi=max(maxi,2+help(j,mp[x],mp,nums,dp));
                }
            }
        }
        return (maxi==INT_MIN?0:maxi);
    }
    int lenLongestFibSubseq(vector<int>& arr) {

        unordered_map<int,int> mp;
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));

        for(int i=0;i<arr.size();i++)
            mp[arr[i]]=i;

       return solve(0,n,mp,arr,dp);

    }
};