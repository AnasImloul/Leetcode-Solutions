class Solution {
public:
    
    int solve(int r1,int c1,int r2,vector<vector<int>>& grid, vector<vector<vector<int>>> &dp)
    {
        //Calculating c2 : 
        /*
        (r1 + c1) = (r2 + c2)
        c2 = (r1 + c1) - r2
        */
        int c2 = (r1+c1)-r2 ; 
        
        //Base condition
if(r1 >= grid.size() || r2 >= grid.size() || c1 >= grid[0].size() || c2 >= grid[0].size() ||                  grid[r1][c1] == -1 || grid[r2][c2] == -1)
    {
        return INT_MIN;
    }
        if(r1 == grid.size()-1 && c1 == grid[0].size()-1)
        {   
            return grid[r1][c1] ;
        }
        
        if(dp[r1][c1][r2] != -1)
        {
            return dp[r1][c1][r2];
        }
        int ch = 0;
        if(r1 == r2 && c1 == c2)
        {
            ch += grid[r1][c1];     
            //if both players are at the same place than collect cherry only one time.
        }
        else
        {
            ch += grid[r1][c1] + grid[r2][c2];
        }
        cout<<ch<<"\n";
        
        //Trying all the possible paths for both the players
        
        int hh = solve(r1, c1+1, r2, grid, dp);
        int vh = solve(r1+1, c1, r2, grid, dp);
        int vv = solve(r1+1, c1, r2+1, grid, dp);
        int hv = solve(r1, c1+1, r2+1, grid, dp);
        
        //collecting maximum cherries from possible paths
        ch += max(max(hh, vh),max(vv, hv)) ; 
        
        dp[r1][c1][r2] = ch;
        
        return ch;    
    }

    
    int cherryPickup(vector<vector<int>>& grid) 
    {
        
        int n = grid.size();
        
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(n,-1)));
        
        int ans = solve(0,0,0,grid,dp) ;
        
        if(ans == INT_MIN || ans <0)
        {
            return 0;
        }
        
        return ans;       
        
    }
};
