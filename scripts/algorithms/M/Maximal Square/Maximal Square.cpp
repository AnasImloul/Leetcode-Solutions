// Runtime: 71 ms (Top 51.33%) | Memory: 19.30 MB (Top 86.07%)

class Solution {
public:
    int dp[301][301];
    int helperMethod(int i,int j,vector<vector<char>>& matrix)
    {
        if(i<0 || j<0 || i>= matrix.size()|| j>=matrix[0].size()|| matrix[i][j] == '0')
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j] = 1+min( helperMethod(i+1,j,matrix),
                            min(helperMethod(i+1,j+1,matrix),helperMethod(i,j+1,matrix))) ;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans = INT_MIN;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                {
                    ans=max(ans,helperMethod(i,j,matrix));
                }
            }
        }
        return ans==INT_MIN?0:ans*ans;
    }
};
