class Solution {
public:
    int dp[1001][1050];
       int mod = 1e9+7;
    int prf(int n, vector<int> &m)
    {
        int d = 0;
        for(int i=0;i<10;i++)
        {
            if(n%m[i]==0)
            d = d| (1<<i);
        }
        return d;
    }
    long long fn(vector<int>& nums,int i,int bt,vector<int> &m)
    {
     
        if(i==nums.size()){
            //cout<<bt<<"\n";
           return 1;
        }
        if(dp[i][bt]!=-1)
            return dp[i][bt];
        
        if(nums[i]%4==0 || nums[i]%9==0 || nums[i]%25==0)
            return dp[i][bt] = fn(nums,i+1,bt,m)%mod;
        
        int d = prf(nums[i],m);
        if((bt&d)>0)
        {
            return dp[i][bt] = fn(nums,i+1,bt,m)%mod;
        }
    return dp[i][bt] = (fn(nums,i+1,bt,m)+ 0LL + fn(nums,i+1,bt|d,m))%mod;
    }
    
    int squareFreeSubsets(vector<int>& nums) {
        vector<int> m = {2,3,5,7,11,13,17,19,23,29};
        int j = 0;
        
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return (fn(nums,0,0,m)-1 + mod)%mod;
    }
};