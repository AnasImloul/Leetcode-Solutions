// Runtime: 259 ms (Top 5.00%) | Memory: 35.9 MB (Top 7.81%)
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                    continue;
                int c=0;
                if(grid[i][j]==1 && (i*j==0 || i==grid.size()-1 || j==grid[0].size()-1))
                {
                    queue<vector<int>> q;
                    q.push({i,j});
                    while(!q.empty())
                    {
                        vector<int> a;
                        a=q.front();
                        q.pop();
                        grid[a[0]][a[1]]=0;
                        if(a[0]+1<grid.size() && grid[a[0]+1][a[1]]==1)
                        {
                            q.push({a[0]+1,a[1]});
                            grid[a[0]+1][a[1]]=0;
                        }
                        if(a[1]+1<grid[0].size() && grid[a[0]][a[1]+1]==1)
                        {
                            q.push({a[0],a[1]+1});
                            grid[a[0]][a[1]+1]=0;
                        }
                        if(a[0]-1>=0 && grid[a[0]-1][a[1]]==1)
                        {
                            q.push({a[0]-1,a[1]});
                            grid[a[0]-1][a[1]]=0;
                        }
                        if(a[1]-1>=0 && grid[a[0]][a[1]-1]==1)
                        {
                            q.push({a[0],a[1]-1});
                            grid[a[0]][a[1]-1]=0;
                        }
                    }
                }
            }
        }
        int m=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                m+=grid[i][j];
            }
        }
        return m;
    }
};