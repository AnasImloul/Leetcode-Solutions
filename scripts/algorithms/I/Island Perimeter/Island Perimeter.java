// Runtime: 10 ms (Top 73.55%) | Memory: 62.3 MB (Top 52.61%)
class Solution {
    public int islandPerimeter(int[][] grid) {
        if(grid == null || grid.length == 0) return 0;

        int row=grid.length,col=grid[0].length;
        int perimeter=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){

                if(grid[i][j]==1){
                    perimeter+=4;

                    if(i>0 && grid[i-1][j]==1){
                    perimeter-=2;
                   }

                    if(j>0 && grid[i][j-1]==1){
                    perimeter-=2;
                   }
                }

            }
        }
        return perimeter;
    }
}