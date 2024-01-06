// Runtime: 75 ms (Top 80.5%) | Memory: 96.50 MB (Top 55.46%)

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0 , row = grid.size(), col = grid[0].size();    
        for(int i = 0 ; i < row ; i++)
        {
           for(int j = 0 ; j < col ; j++)
           {
               if( grid[i][j])
               {
                  ans+=4;
                  if(i < row - 1 && grid[i+1][j])ans--; 
                  if(j < col -1 && grid[i][j+1])ans--; 
                  if(j  && grid[i][j-1])ans--; 
                  if(i  && grid[i-1][j])ans--; 
               }
           } 
        }
        return ans;
    }
};
