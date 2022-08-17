class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int m = wordDict.size();
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i >= wordDict[j].size())
                {
                    for(int k = 0; k < wordDict[j].size(); k++)
                    {
                        if(s[i-wordDict[j].size()+k] != wordDict[j][k])
                            goto cnt;
                    }
                    if(dp[i-wordDict[j].size()] == 1) 
                        dp[i] = 1;
                    if(dp[n] == 1) 
                        return true;
                    cnt:;
                }
            }
        }
        return dp[n];
    }
};
