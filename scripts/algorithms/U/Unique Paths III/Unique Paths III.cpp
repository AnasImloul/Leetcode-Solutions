// Runtime: 3 ms (Top 80.41%) | Memory: 7.1 MB (Top 29.42%)
class Solution {
public:
    int dfs(vector<vector<int>>&grid,int x,int y,int zero){
        // Base Condition
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1){
            return 0;
        }
        if(grid[x][y] == 2){
            return zero == -1 ? 1 : 0; // Why zero = -1, because in above example we have 9 zero's. So, when we reach the final cell we are covering one cell extra that means if all zero all covered then on reaching final it will make zero count = -1
            // If that's the case we find the path and return '1' otherwise return '0';
        }
        grid[x][y] = -1; // mark the visited cells as -1;
        zero--; // and reduce the zero by 1

        int totalPaths = dfs(grid, x + 1, y, zero) + // calculating all the paths available in 4 directions
            dfs(grid, x - 1, y, zero) +
            dfs(grid, x, y + 1, zero) +
            dfs(grid, x, y - 1, zero);

        // Let's say if we are not able to count all the paths. Now we use Backtracking over here
        grid[x][y] = 0;
        zero++;

        return totalPaths; // if we get all the paths, simply return it.
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
       int start_x,start_y=0,cntzero=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) cntzero++;
               else if(grid[i][j]==1){
                    start_x=i;
                    start_y=j;
                }
            }
        }
      return dfs(grid,start_x,start_y,cntzero);

    }
};