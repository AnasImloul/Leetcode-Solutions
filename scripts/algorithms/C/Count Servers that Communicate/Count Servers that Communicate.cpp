// Runtime: 72 ms (Top 82.64%) | Memory: 22.7 MB (Top 21.95%)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] && !visited[i][j])
                {
                    bool flag=false;
                    for(int x=0;x<n;x++)
                    {
                        if(x!=i && grid[x][j] && !visited[x][j])
                            visited[x][j]=true,flag=true;
                        if(!flag && x!=i && visited[x][j])
                            flag=true;
                    }
                    for(int x=0;x<m;x++)
                    {
                        if(x!=j && grid[i][x] && !visited[i][x])
                            visited[i][x]=true,flag=true;
                        if(!flag && x!=j && visited[i][x])
                            flag=true;
                    }
                    if(flag)
                        visited[i][j]=true;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(visited[i][j])
                    ans++;

        return ans;
    }
};