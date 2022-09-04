// Runtime: 3 ms (Top 54.99%) | Memory: 51.8 MB (Top 39.25%)
class Solution {
        boolean isClosed = true;

    public void solve(char[][] board) {
        int m = board.length;
        int n = board[0].length;

        // To identify all those O which are adjacent and unbounded by 'X', we put a temporary value
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && (i == 0 || j == 0 || i == m-1 || j == n-1) ){
                     dfs(board, i, j);
                }
            }
        }

        // revert the temperoray value and also replace remaining O with X
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'T') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }

    }

    public void dfs(char[][] board, int i, int j){
        if(i<0 || j<0 || i>= board.length || j>=board[0].length || board[i][j] != 'O') return;

        board[i][j] = 'T'; // to put a temperory mark/ to mark as visited

        dfs(board, i, j+1); // Top
        dfs(board, i, j-1); // Bottom
        dfs(board, i+1, j); // Right
        dfs(board, i-1, j); // Left
    }
}