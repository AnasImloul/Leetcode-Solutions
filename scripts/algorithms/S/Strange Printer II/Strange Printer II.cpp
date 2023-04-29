class Solution {
    struct Bounds {
        int left, right, top, bottom;
        Bounds() : left(INT_MAX), 
                   right(INT_MIN),
                   top(INT_MAX), 
                   bottom(INT_MIN)
                   {}
    };
    unordered_map<int, Bounds> colors;
    
    bool cycle(vector<vector<int>>& grid, int col){
        for (int i = colors[col].top; i <= colors[col].bottom; ++i){
            for (int j = colors[col].left; j <= colors[col].right; ++j){
                if (grid[i][j] == -1) return true; // already visited and unresolved!
                else if (grid[i][j] == col) grid[i][j] = -1; // mark visiting
                else if (grid[i][j] && cycle(grid, grid[i][j])) return true;
            }
        }
        
        for (int i = colors[col].top; i <= colors[col].bottom; ++i){
            for (int j = colors[col].left; j <= colors[col].right; ++j){
                grid[i][j] = 0; // resolved
            }
        }
        
        return false;
    }
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        for (int i = 0; i < targetGrid.size(); ++i){
            for (int j = 0; j < targetGrid[0].size(); ++j){
                colors[targetGrid[i][j]].left = min(colors[targetGrid[i][j]].left, j);
                colors[targetGrid[i][j]].top = min(colors[targetGrid[i][j]].top, i);
                colors[targetGrid[i][j]].right = max(colors[targetGrid[i][j]].right, j);
                colors[targetGrid[i][j]].bottom = max(colors[targetGrid[i][j]].bottom, i);
            }
        }
        
        for (int i = 0; i < targetGrid.size(); ++i){
            for (int j = 0; j < targetGrid[0].size(); ++j){
                if (targetGrid[i][j] && cycle(targetGrid, targetGrid[i][j])) return false;
            }
        }
        
        return true;
    }
};