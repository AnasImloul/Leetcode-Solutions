// Runtime: 51 ms (Top 84.03%) | Memory: 27.8 MB (Top 21.38%)
class Solution {
public:
    bool match(int i, int j, string &a, string &b, vector<vector<int>>&dp)
    {
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0)
        {
            for(;j>-1;j--) if(b[j]!='*') return false;
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j] || b[j]=='?') return dp[i][j] = match(i-1,j-1,a,b,dp);
        if(b[j]=='*') return dp[i][j] = (match(i-1,j,a,b,dp) | match(i,j-1,a,b,dp));
        return false;
    }
    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return match(n-1,m-1,s,p,dp);
    }
};