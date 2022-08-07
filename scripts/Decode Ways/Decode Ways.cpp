class Solution {
public:
    int numDecodings(string s) {
        
        if(s[0] == 0)
            return 0;
        int n  = s.length();
       vector<int> dp(n+1, 0);
        
        //Storing DP[n-1]
        if(s[n-1] == '0' )
            dp[n-1] = 0;
        else 
            dp[n-1] = 1;
        
        if(n == 1)
            return dp[0];
        
        //Storing DP[n-2]
            if(s[n-2] == '0')
                dp[n-2] = 0;
            else
            {
                string temp ;
                temp.push_back(s[n-2]);
                temp.push_back(s[n-1]);
                
                int x = stoi(temp);
                if(x<27)
                    dp[n-2] = 1;
                dp[n-2] += dp[n-1];
            }
        
        
        for(int i = n-3; i>=0 ; i--)
        {
            if(s[i] == '0')
                continue;
            
            string temp ;
                temp.push_back(s[i]);
                temp.push_back(s[i+1]);
                
                int x = stoi(temp);
                if(x<27)
                    dp[i] = dp[i+2];
                dp[i]+=dp[i+1];
        }
        
        return dp[0];
    }
};
