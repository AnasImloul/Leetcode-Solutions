// Runtime: 39 ms (Top 18.09%) | Memory: 13.4 MB (Top 72.47%)
// marking element -ve and then fix it while backtracking worked as visited matrix
// marking element 1e9 and not fixing it while backtracking works for coloring element
class Solution {
private:
    int m,n;
public:
    bool is_valid(int i,int j,vector<vector<int>> &grid,int org_color){
        return i >= 0 and j >= 0 and i < m and j < n and grid[i][j] == org_color and grid[i][j] > 0;
    }

    bool is_colorable(int i,int j,vector<vector<int>> &grid,int org_color){
        if(i == 0 or j == 0 or i == m-1 or j == n-1) return true; // boundary condn

        // checking any of the neighbour is of opposite color or not
        if(i-1 >= 0 and abs(grid[i-1][j]) != org_color and grid[i-1][j] != 1e9) return true;

        if(i+1 < m and abs(grid[i+1][j]) != org_color and grid[i+1][j] != 1e9) return true;

        if(j-1 >= 0 and abs(grid[i][j-1]) != org_color and grid[i][j-1] != 1e9) return true;

        if(j+1 < n and abs(grid[i][j+1]) != org_color and grid[i][j+1] != 1e9) return true;

        return false;
    }

    void dfs(int i,int j,vector<vector<int>> &grid,int org_color){
        if(!is_valid(i,j,grid,org_color)) return;

        if(is_colorable(i,j,grid,org_color)) grid[i][j] = 1e9;
        else grid[i][j] = -grid[i][j];

        dfs(i-1,j,grid,org_color); dfs(i+1,j,grid,org_color); // up and down
        dfs(i,j-1,grid,org_color); dfs(i,j+1,grid,org_color); // left and right

        if(grid[i][j] < 0) grid[i][j] = -grid[i][j];
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color){
        m = grid.size(), n = grid[0].size();
        dfs(row,col,grid,grid[row][col]);
        for(auto &it : grid){
            for(auto &i : it){
                if(i == 1e9) i = color;
            }
        }
        return grid;
    }
};