class Solution {
public:
    int solve(int i, int j, int m , int n, vector<vector<int>> &grid)
    {
        // if we come out of the grid simply return a large value
        if(i >= m || j >= n)
            return INT_MAX;
        
        // calucate health by the 2 possible ways
        int down = solve(i + 1, j, m, n, grid);
        int right = solve(i, j + 1, m, n, grid);
        
		// take the min both both
        int health = min(down, right);
        
        // we reach the destination when both the sides return INT_MAX
        if(health == INT_MAX)
        {
            health = 1; // both are +ve large integers so min health required = 1
        }
        
        int ans = 0;
        if(health - grid[i][j] > 0)
        {
            ans = health - grid[i][j];
        }
        else
        {
            ans = 1;
        }
             
        return ans;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        return solve(0, 0, m, n, dungeon);
    }
};
