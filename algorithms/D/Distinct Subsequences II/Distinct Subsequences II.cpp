class Solution {
public:
    int distinctSubseqII(string s) {
      
        int n=s.length();
        int mod=1e9+7;
        
        vector<long long>dp(n+1);
        unordered_map<char,int>mp;
        
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=(2*dp[i-1])%mod;
            char ch=s[i-1];
            
            if(mp.find(ch)!=mp.end())
            {
                int j=mp[ch];
                dp[i]=(dp[i]-dp[j-1]+mod)%mod;
            }
            mp[s[i-1]]=i%mod;
            
        }
        return dp[n]-1;
    }
};
