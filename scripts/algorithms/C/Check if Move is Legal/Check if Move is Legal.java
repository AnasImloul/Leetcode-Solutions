// Runtime: 0 ms (Top 100.0%) | Memory: 41.24 MB (Top 69.6%)

class Solution {
    public boolean checkMove(char[][] board, int rMove, int cMove, char color) {

        int[][] direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

        for(int[] d : direction)
        {
            if(dfs(board,rMove,cMove,color,d,1))
                return true;
        }
        return false;
    }

    public boolean dfs(char[][] board, int r, int c, char color,int[] direcn,int len)
    {

        int nr = r + direcn[0];
        int nc = c + direcn[1];

        if( nr<0 || nc<0 || nr>7 || nc>7) return false;

        if(board[nr][nc] == color)
        {
            if(len>=2) return true;
            else
                return false;
        }
        else
        {
            if(board[nr][nc] == '.')
            {  
                return false;
            }
            return dfs(board,nr,nc,color,direcn,len+1);
        }
    }
}