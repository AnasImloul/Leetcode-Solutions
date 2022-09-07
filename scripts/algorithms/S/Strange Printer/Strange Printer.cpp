// Runtime: 1755 ms (Top 5.17%) | Memory: 312.6 MB (Top 5.17%)
class Solution {
public:
    int dp[101][101];
    int solve(string s,int i,int j)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        while(i<j && s[i+1]==s[i])
            i++;
        while(i<j && s[j]==s[j-1])
        {
            j--;
        }
        ans=1+solve(s,i+1,j);
        for(int k=i+1;k<=j;k++)
        {
            if(s[k]==s[i])
            {
                int cnt=solve(s,i+1,k-1)+solve(s,k,j);
                ans=min(ans,cnt);
            }
        }
        return dp[i][j]=ans;
    }
    int strangePrinter(string s)
    {
        memset(dp,-1,sizeof(dp));
         return solve(s,0,s.size()-1);
    }
};
// if you like the solution plz upvote.