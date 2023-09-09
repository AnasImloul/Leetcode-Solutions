// Runtime: 891 ms (Top 82.1%) | Memory: 15.48 MB (Top 61.3%)

class Solution 
{
public:
    int dp[8000][71];
    int n,m;
    int find(vector<vector<int>>&mat,int r,int sum,int &target)
    {
        if(r>=n)
        {
            return abs(sum-target);
        }
        if(dp[sum][r]!=-1)
        {
            return dp[sum][r];
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++)
        {
            ans=min(ans,find(mat,r+1,sum+mat[r][i],target));
            if(ans==0)
            {
                break;
            }
        }
        return dp[sum][r]=ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) 
    {
        memset(dp,-1,sizeof(dp));
        n=mat.size();
        m=mat[0].size();
        return find(mat,0,0,target);
    }
};