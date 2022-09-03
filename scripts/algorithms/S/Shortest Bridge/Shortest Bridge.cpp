// Runtime: 116 ms (Top 35.20%) | Memory: 20.3 MB (Top 68.99%)
class Solution {
public:
    void findOneIsland(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q){
        if(i<0 || j<0 || i==grid.size() || j==grid.size() || grid[i][j]!=1)
            return;
        grid[i][j] = 2;
        q.push({i,j});

        findOneIsland(grid, i, j-1, q);
        findOneIsland(grid, i, j+1, q);
        findOneIsland(grid, i-1, j, q);
        findOneIsland(grid, i+1, j, q);

    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        int res=0;
        bool OneIslandFound = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    OneIslandFound = true;
                    findOneIsland(grid, i, j, q);
                    break;
                }
            }
            if(OneIslandFound)
                break;
        }

        while(!q.empty()){
            int i=q.front().first, j=q.front().second;
            q.pop();
            if(i!=0 && grid[i-1][j]<2){
                if(grid[i-1][j]==1){
                    res = grid[i][j]-2;
                    break;
                }
                if(grid[i-1][j]==0){
                    grid[i-1][j] = grid[i][j]+1;
                    q.push({i-1, j});
                }
            }

            if(i!=grid.size()-1 && grid[i+1][j]<2){
                if(grid[i+1][j]==1){
                    res = grid[i][j]-2;
                    break;
                }
                if(grid[i+1][j]==0){
                    grid[i+1][j] = grid[i][j]+1;
                    q.push({i+1, j});
                }
            }

            if(j!=0 && grid[i][j-1]<2){
                if(grid[i][j-1]==1){
                    res = grid[i][j]-2;
                    break;
                }
                if(grid[i][j-1]==0){
                    grid[i][j-1] = grid[i][j]+1;
                    q.push({i, j-1});
                }
            }

            if(j!=grid.size()-1 && grid[i][j+1]<2){
                if(grid[i][j+1]==1){
                    res = grid[i][j]-2;
                    break;
                }
                if(grid[i][j+1]==0){
                    grid[i][j+1] = grid[i][j]+1;
                    q.push({i, j+1});
                }
            }
        }
        return res;
    }
};