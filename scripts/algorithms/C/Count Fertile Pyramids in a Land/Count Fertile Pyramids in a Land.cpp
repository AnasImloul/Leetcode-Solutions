class Solution {
public:
    int f(vector<vector<int>>&grid, int i, int j, vector<vector<int>>&dp){
        if(j<0 || j>=grid[0].size() || !grid[i][j]) return -1;
        else if(dp[i][j]!=-1) return dp[i][j];
		
        if(i+1>=grid.size() || !grid[i+1][j]) return dp[i][j] = 0;
        return dp[i][j] =  1 + min(f(grid, i+1, j-1, dp), f(grid, i+1, j+1, dp));
    }
    int countPyramids(vector<vector<int>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        
        for(int i=0; i<n-1; i++)
            for(int j=0; j<m-1; j++)
                if(grid[i][j]) res+=f(grid, i, j, dp);
        
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        reverse(grid.begin(), grid.end());//flip the grid to consider upside-down pyramid
        
        for(int i=0; i<n-1; i++)
            for(int j=0; j<m-1; j++)
                if(grid[i][j]) res+=f(grid, i, j, dp);
        
        return res;
    }
};
