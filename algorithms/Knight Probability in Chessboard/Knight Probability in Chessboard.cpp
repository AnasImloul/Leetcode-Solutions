class Solution {
public:
    
    // declare a dp
    
    double dp[30][30][105];
    
    // x and y co-ordinates of 8 directions
   
    vector<int> dx = {-2, -2, -1, 1, 2, 2, 1, -1};
    
    vector<int> dy = {-1, 1, 2, 2, 1, -1, -2, -2};
    
    double dfs(int i, int j, int n, int moves)
    {
        // base case if we have reached out of grid
        
        if(i < 0 || i >= n || j < 0 || j >= n)
            return 0;
        
        // if no moves are remaining
        
        if(moves <= 0)
            return 1;
        
        // if already calculated
        
        if(dp[i][j][moves] != 0)
            return dp[i][j][moves];
        
        // find total possible ways of staying on chess board
        
        double ans = 0;
        
        for(int k = 0; k < 8; k++)
        {
            int new_row = i + dx[k];
            
            int new_col = j + dy[k];
            
            ans += dfs(new_row, new_col, n, moves - 1);
        }
        
        // for each cell there are 8 possible moves, so probablity will be no. of successfull moves / 8
        
        // store the result and return
        
        return dp[i][j][moves] = ans / 8.0;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        
        // initialize the dp with 0
        
        memset(dp, 0, sizeof(dp));
       
        return dfs(row, column, n, k);
    }
};
