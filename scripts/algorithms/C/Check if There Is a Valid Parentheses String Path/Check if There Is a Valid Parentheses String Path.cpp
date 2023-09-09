// Runtime: 677 ms (Top 15.4%) | Memory: 125.54 MB (Top 33.7%)

class Solution {
public:
    int n,m;
    int dp[101][101][200];
    bool find(vector<vector<char>>& mat,int row,int col,int open)
    {
        if(row<0||col<0||row>=n||col>=m||open<0)
        {
            return false;
        }
        if(dp[row][col][open]!=-1)
        {
            return dp[row][col][open];
        }
        if(row==n-1&&col==m-1)
        {
            if(mat[row][col]=='(')
            {
                open++;
            }
            else 
            {
                open--;
            }
            return open==0;
        }
        if(mat[row][col]=='(')
        {
            if(find(mat,row+1,col,open+1)||find(mat,row,col+1,open+1))
            {
                return true;
            }
        }
        else
        {
            if(find(mat,row+1,col,open-1)||find(mat,row,col+1,open-1))
            {
                return true;
            }
        }
        return dp[row][col][open]=false;
    }
    bool hasValidPath(vector<vector<char>>& mat) 
    {
        memset(dp,-1,sizeof(dp));
        n=mat.size();
        m=mat[0].size();
        return find(mat,0,0,0);
    }
};