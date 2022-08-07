class Solution {
public:
    int dp[101][101];
    int paths(int i,int j,int &m, int &n,vector<vector<int>> &grid){
        if(i>=m || j>=n) return 0;
        
        if(grid[i][j] == 1) return 0;
        
        if(i== m-1 && j== n-1) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int v = paths(i,j+1,m,n,grid);
        int h = paths(i+1,j,m,n,grid);
        
        return dp[i][j] = v + h;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        memset(dp,-1,sizeof(dp));
        
        return paths(0,0,m,n,obstacleGrid);
    }
};
