class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>>&grid) {
        if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 0) {
            return true;
        }
        return false;
    }
    void DFS(int i,int j,vector<vector<int>>&grid) {
        grid[i][j] = 1;
        if(isValid(i + 1,j,grid)) {
            DFS(i + 1,j,grid);
        }
        if(isValid(i - 1,j,grid)) {
            DFS(i - 1,j,grid);
        }
        if(isValid(i,j + 1,grid)) {
            DFS(i,j + 1,grid);
        }
        if(isValid(i,j - 1,grid)) {
            DFS(i,j - 1,grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++) {
            int j = 0;
            if(grid[i][j] == 0) {
                DFS(i,j,grid);
            }
            j = n - 1;
            if(grid[i][j] == 0) {
                DFS(i,j,grid);
            }
        }
        for(int j = 0; j < n; j++) {
            int i = 0;
            if(grid[i][j] == 0) {
                DFS(i,j,grid);
            }
            i = m - 1;
            if(grid[i][j] == 0) {
                DFS(i,j,grid);
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    cnt++;
                    DFS(i,j,grid);
                }
            }
        }
        return cnt;
    }
};
