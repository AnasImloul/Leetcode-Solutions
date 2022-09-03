// Runtime: 0 ms (Top 100.00%) | Memory: 41.9 MB (Top 100.00%)
class Solution {
    public char[][] updateBoard(char[][] board, int[] click) {
        int r = click[0];
        int c = click[1];
        if(board[r][c] == 'M')
        {
            board[r][c] = 'X';
            return board;
        }
        dfs(board, r, c);
        return board;
    }

    private void dfs(char[][]board, int r, int c)
    {
        if(r < 0 || r >= board.length || c >= board[0].length || c < 0 || board[r][c] == 'B')//Stop case
            return;
        int num = countMine(board, r, c);//count how many adjacent mines
        if(num != 0)
        {
            board[r][c] = (char)('0' + num);
            return;
        }
        else
        {
            board[r][c] = 'B';
            dfs(board, r + 1, c);//recursively search all neighbors
            dfs(board, r - 1, c);
            dfs(board, r, c + 1);
            dfs(board, r, c - 1);
            dfs(board, r - 1, c - 1);
            dfs(board, r + 1, c - 1);
            dfs(board, r - 1, c + 1);
            dfs(board, r + 1, c + 1);
        }
    }

    private int countMine(char[][]board, int r, int c)
    {
        int count = 0;
        for(int i = r - 1; i <= r + 1; ++i)
        {
            for(int j = c - 1; j <= c + 1; ++j)
            {
                if(i >= 0 && i < board.length && j >= 0 && j < board[0].length)
                {
                    if(board[i][j] == 'M')
                        count++;
                }
            }
        }
        return count;
    }
}