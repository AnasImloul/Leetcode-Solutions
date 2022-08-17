class Solution {
    public int[][] colorBorder(int[][] grid, int row, int col, int color) {
    dfs(grid,row,col,grid[row][col]);
        for(int i = 0;i<grid.length;i++)
        {
            for(int j = 0;j<grid[0].length;j++)
            {
               if(grid[i][j]<0)
               {
                   grid[i][j] = color;
               }
            }
        }
     
        
        return grid;
    }
    int[][] dirs = {{0,1},{1,0},{0,-1},{-1,0}};
      public void dfs(int[][] grid, int row, int col, int color) {
        grid[row][col] = - color;
          int count = 0;
         for(int i = 0;i<4;i++)
         {
             int rowdash = row+dirs[i][0];
             int coldash = col+dirs[i][1];
             
             if(rowdash<0||coldash<0||rowdash>=grid.length||coldash>=grid[0].length||
               Math.abs(grid[rowdash][coldash])!=color)
             {
                 continue;
             }
             count++;
             
             if(grid[rowdash][coldash]==color)
             {
                 dfs(grid,rowdash,coldash,color);
             }
     
         }
          if(count==4)
          {
              grid[row][col] = color;
          }
      
    }
}
