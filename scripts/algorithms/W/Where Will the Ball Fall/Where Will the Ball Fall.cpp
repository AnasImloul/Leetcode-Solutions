// Runtime: 35 ms (Top 78.20%) | Memory: 13.2 MB (Top 52.18%)
class Solution {
public:
    int util(vector<vector<int>>&grid,bool top,int i,int j)
    {
        if(top==0&&i==grid.size()-1)return j;
        if(top==1)
        {
            if(grid[i][j]==1)
            {
                if(j+1>=grid[0].size()||grid[i][j+1]==-1)return -1;
                return util(grid,!top,i,j+1);
            }
            else
            {
                if(j-1<0||grid[i][j-1]==1)return -1;
                return util(grid,!top,i,j-1);
            }
        }
        else
        {
            return util(grid,!top,i+1,j);
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans(grid[0].size(),-1);
        for(int i=0;i<grid[0].size();i++)
        {
            ans[i]=util(grid,true,0,i);
        }
        return ans;
    }
};