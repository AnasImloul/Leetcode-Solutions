// Runtime: 11 ms (Top 84.26%) | Memory: 54.7 MB (Top 92.39%)

    class Solution {
    public int numEnclaves(int[][] grid) {
        int maxcount = 0;
        // if(grid.length==10)
        // {
        // return 3;
        // }
        for(int i = 0;i<grid.length;i++)
          {
              for(int j = 0;j<grid[0].length;j++)
              {
                  if(grid[i][j] ==0)
                  {
                      continue;
                  }
                  if(i==0||i==grid.length-1||j==grid[0].length-1||j==0)
                  {
                        dfs(grid,i,j);
                  }

              }
        }
        int count = 0;
      for(int i = 0;i<grid.length;i++)
          {

              for(int j = 0;j<grid[0].length;j++)
              {

                  if(grid[i][j]==1)
                  {
                      count++;
                  }

              }
        }

        return count;
    }
    int[][] dirs = {{0,1},{1,0},{0,-1},{-1,0}};

      public void dfs(int[][] grid,int row,int col) {

           grid[row][col] = 0;
             for(int k = 0;k<4;k++)
         {
             int rowdash = row+dirs[k][0];
             int coldash = col+dirs[k][1];

             if(rowdash<0||coldash<0||rowdash>=grid.length||coldash>=grid[0].length||
              grid[rowdash][coldash]==0)
             {
                 continue;
             }

             if(grid[rowdash][coldash]==1)
             {
               dfs(grid,rowdash,coldash);
             }

         }

    }
}