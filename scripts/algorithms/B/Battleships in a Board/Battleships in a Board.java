// Runtime: 4 ms (Top 10.56%) | Memory: 44.7 MB (Top 26.11%)
class Solution {
    public int countBattleships(char[][] board) {
            int result = 0;
            for(int i = 0;i<board.length;i++)
            {
                for(int j = 0;j<board[i].length;j++)
                {
                    if(board[i][j] == 'X')
                    {
                        remover(i, j, board);
                        result++;
                    }

                }
            }
            return result;

        }
        public void remover(int i , int j, char[][] board)
        {
            if(i<0 || i>= board.length || j<0 || j>=board[0].length || board[i][j] == '.')
            {
                return;
            }
            board[i][j] = '.';
            remover(i+1, j, board);
            remover(i, j+1, board);
        }
}