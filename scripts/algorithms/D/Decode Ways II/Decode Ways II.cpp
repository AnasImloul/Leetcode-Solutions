class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(s[0]=='0')
        {
            return 0;
        }
        for(int i=0;i<n-1;++i)
        {
            if(s[i]==s[i+1]&&s[i]=='0')
            {
                return 0;
            }
        }
        long long dp[n][2],mod=1e9+7;
        //dp[i][0]-no of ways such that 0...i has been mapped with ith digit is mapped alone
        //dp[i][1]-no of ways such that 0...i has been mapped with ith digit is mapped with previous digit
        dp[0][0]=(s[0]=='*'?9:1);
        dp[0][1]=0;
        for(int i=1;i<n;++i)
        {
            if(s[i]!='0')
            {
                if(s[i]=='*')
                {
                    long long m=9;
                    dp[i][0]=((m%mod)*((dp[i-1][0]+dp[i-1][1])%mod))%mod;
                }
                else
                {
                    dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
                }
            }
            else
            {
                dp[i][0]=0;
            }
            
            if(s[i-1]=='0')
            {
                dp[i][1]=0;
            }
            else
            {
                if(s[i-1]=='*'||s[i]=='*')
                {
                    long long m=1;
                    if(s[i-1]=='*'&&s[i]=='*')
                    {
                        m=15;
                    }
                    else if(s[i-1]=='*')
                    {
                        int u=s[i]-'0';
                        if(u>6)
                        {
                            m=1;
                        }
                        else
                        {
                            m=2;
                        }
                    }
                    else
                    {
                        int v=s[i-1]-'0';
                        if(v>2)m=0;
                        else
                        {
                            if(v==1)m=9;
                            else m=6;
                        }
                    }
                    if(i-2>=0)dp[i][1]=((m%mod)*((dp[i-2][0]+dp[i-2][1])%mod))%mod;
                    else dp[i][1]=m;
                }
                else
                {
                    int v=(s[i-1]-'0')*10+(s[i]-'0');
                    if(v>=1&&v<=26)
                    {
                        if(i-2>=0)dp[i][1]=(dp[i-2][0]+dp[i-2][1])%mod;
                        else dp[i][1]=1;
                    }
                    else
                    {
                        dp[i][1]=0;
                    }
                }
                
            }
            
        }
        return (dp[n-1][0]+dp[n-1][1])%mod;
    }
};
