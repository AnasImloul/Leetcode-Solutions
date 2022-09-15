// Runtime: 236 ms (Top 95.64%) | Memory: 8.4 MB (Top 7.64%)
class Solution {
public:
    int maxgold=0;
    int m,n;
    void gold(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int count){
// Down
        if(i+1<m && !vis[i+1][j] && grid[i+1][j]){
            vis[i][j]=1;
            gold(i+1,j,grid,vis,count+grid[i+1][j]);
            vis[i][j]=0;
        }
// Left
        if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]){
            vis[i][j]=1;
            gold(i,j-1,grid,vis,count+grid[i][j-1]);
            vis[i][j]=0;
        }
// Right
        if(j+1<n && !vis[i][j+1] && grid[i][j+1]){
            vis[i][j]=1;
            gold(i,j+1,grid,vis,count+grid[i][j+1]);
            vis[i][j]=0;
        }
// Up
        if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]){
            vis[i][j]=1;
            gold(i-1,j,grid,vis,count+grid[i-1][j]);
            vis[i][j]=0;
        }
        maxgold=max(maxgold,count);
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    vector<vector<int>>vis(m,vector<int>(n,0));
                    gold(i,j,grid,vis,grid[i][j]);
                }
            }
        }
        return maxgold;
    }
};