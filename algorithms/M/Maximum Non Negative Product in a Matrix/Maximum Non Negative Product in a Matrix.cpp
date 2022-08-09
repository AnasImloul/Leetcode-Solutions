const long long MOD = 1e9 + 7;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        long long mx[20][20] = {0};
        long long mn[20][20] = {0};
        int row = grid.size(), col = grid[0].size();
        
        // Init
        mx[0][0] = mn[0][0] = grid[0][0];
        
        // Init the row0 and col0 to be the continuous multiply of the elements.
        for(int i = 1; i < row; i++){
            mx[i][0] = mn[i][0] = mx[i - 1][0] * grid[i][0];
        }
        for(int j = 1; j < col; j++){
            mx[0][j] = mn[0][j] = mx[0][j - 1] * grid[0][j];
        }
        
        // DP as the explanation picture shows
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                mx[i][j] = max(max(mx[i - 1][j], mx[i][j - 1]) * grid[i][j], min(mn[i - 1][j], mn[i][j - 1]) * grid[i][j]);
                mn[i][j] = min(max(mx[i - 1][j], mx[i][j - 1]) * grid[i][j], min(mn[i - 1][j], mn[i][j - 1]) * grid[i][j]);
            }
        }
        
        return mx[row - 1][col - 1] < 0 ? -1 : mx[row - 1][col - 1] % MOD;
    }
};
