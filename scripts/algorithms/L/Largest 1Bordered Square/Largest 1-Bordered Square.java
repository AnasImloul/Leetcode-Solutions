// Runtime: 27 ms (Top 15.68%) | Memory: 49.3 MB (Top 21.61%)
class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        // rows[r][c] is the length of the line ended at [r,c] on row r
        int[][] rows=new int[m][n];
        // the length of the line ended at [r,c] on colume c
        int[][] cols=new int[m][n];
        int res=0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0){
                    rows[r][c]=0;
                    cols[r][c]=0;
                }else{
                    rows[r][c]=c==0?1:rows[r][c-1]+1;
                    cols[r][c]=r==0?1:cols[r-1][c]+1;
                    if(res>=rows[r][c]||res>=cols[r][c]){
                        continue;
                    }
                    res=Math.max(res,getD(rows,cols,r,c));
                }
            }
        }
        return res*res;
    }

    // get the dimension of the largest square which bottom-right point is [row,col]
    private int getD(int[][] rows,int[][] cols,int row,int col){
        int len=Math.min(rows[row][col],cols[row][col]);
        for(int i=len-1;i>=0;i--){
            if(rows[row-i][col]>i && cols[row][col-i]>i){
                return i+1;
            }
        }
        return 1;
    }
}