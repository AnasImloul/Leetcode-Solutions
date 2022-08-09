/*
Convert grid to 3*n X 3*n grid where eacah of the cell is upscalled to 3x3 grid
and then map the diagonal to 0 or 1 depending on '/' or '\' type in the grid.

Example:
["/\\","\\/"] this can be converted to following scaled grid:

1 1 0 0 1 1 
1 0 1 1 0 1 
0 1 1 1 1 0 
0 1 1 1 1 0 
1 0 1 1 0 1 
1 1 0 0 1 1 

Once this conversion is done, then its simple island count problem, run dfs from each cell 
to visit all cells and count number of times dfs is started and return it as answer.
*/

class Solution {
public:
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void dfs(vector<vector<int>>& g, vector<vector<int>>& vis, int i, int j){
        for(int d = 0; d<4; ++d){
            int x = i + dir[d][0];
            int y = j + dir[d][1];
            if( x >= 0 && y >= 0 && x < g.size() && y < g.size() && 
                vis[x][y] == -1 && g[x][y] == 1){
                vis[x][y] = 1;
                dfs(g, vis, x, y);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> g(3*n, vector<int> (3*n, 1)); 
        for(int i = 0; i < n; ++i){
            for(int j = 0; j< n; ++j){
                if(grid[i][j] == '\\'){
                   for(int k = 0; k < 3; ++k) g[3*i+k][3*j+k] = 0;
                }
                else if(grid[i][j] == '/'){
                   for(int k = 0; k < 3; ++k) g[3*i+k][3*j+ 2-k] = 0;
                }
            }
        }
        int count = 0;
        vector<vector<int>> vis(3*n, vector<int> (3*n, -1));
        
        for(int i = 0; i < 3*n; ++i){
            for(int j = 0; j < 3*n; ++j){
                if(vis[i][j] == -1 && g[i][j] == 1){ //cout<<i<<" "<<j<<endl;
                    count++;
                    vis[i][j] = 1;
                    dfs(g, vis, i, j);
                }
            }
        }
         
        return count;
    }
};
