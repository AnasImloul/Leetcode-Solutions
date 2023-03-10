class Solution {
public:
    
    // declare a dp
    
    int dp[205][205];
    
    // direction coordinates of left, right, up, down
    
    vector<int> dx = {-1, 0, 1, 0};
    
    vector<int> dy = {0, 1, 0, -1};
    
    // dfs function
    
    int dfs(vector<vector<int>>& matrix, int i, int j, int n, int m)
    {
        // if value is already calculated for (i, j)th cell
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // take the maximum of longest increasing path from all four directions
        
        int maxi = 0;
        
        for(int k = 0; k < 4; k++)
        {
            int new_i = i + dx[k];
            
            int new_j = j + dy[k];
            
            if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && matrix[new_i][new_j] > matrix[i][j])
            {
                maxi = max(maxi, dfs(matrix, new_i, new_j, n, m));
            }
        }
        
        // store the res and return it
        
        return dp[i][j] = 1 + maxi;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        int m = matrix[0].size();
        
        // initialize dp with -1
        
        memset(dp, -1, sizeof(dp));
        
        // find the longest increasing path for each cell and take maximum of it
        
        int maxi = INT_MIN;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int ans = dfs(matrix, i, j, n, m);
                
                maxi = max(maxi, ans);
            }
        }
        
        return maxi;
    }
};