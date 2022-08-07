Simple backtracking logic, try out each row and col and check position is valid or not.

since we are going row one by one, there is no way queen is placed in that row.

so, we need to check col, diagonals for valid position.

// col is straightforward flag for each column

// dia1
// 0 1 2 3
// 1 2 3 4
// 2 3 4 5
// 3 4 5 6

// dia2
// 0 -1 -2 -3
// 1  0 -1 -2
// 2  1  0 -1
// 3  2  1  0

negative numbers are not allowed as index, so we add n - 1 to diagonal2.

class Solution {
    List<List<String>> ans = new LinkedList<>();
    int n;
    public List<List<String>> solveNQueens(int n) {
        this.n = n;
        int[][] board = new int[n][n];
        
        boolean[] col = new boolean[n];
        boolean[] dia1 = new boolean[2 * n];
        boolean[] dia2 = new boolean[2 * n];
        
        solve(0, col, dia1, dia2, board);
        return ans;
    }
    
    public void solve(int row, boolean[] col, boolean[] dia1, boolean[] dia2, int[][] board){
        if(row == n){
            copyBoardToAns(board);
            return;
        }
        // brute force all col in that row
        for(int i = 0; i < n; i++){
            if(isValid(col, dia1, dia2, i, row)){
                col[i] = true; dia1[row + i] = true; dia2[row - i + n - 1] = true;
                board[row][i] = 1;
                solve(row + 1, col, dia1, dia2, board);
                col[i] = false; dia1[row + i] = false; dia2[row - i + n - 1] = false;
                board[row][i] = 0;
            }
        }
    }
    
    public boolean isValid(boolean[] col, boolean[] dia1, boolean[] dia2, int curCol, int curRow){
        return !col[curCol] && !dia1[curCol + curRow] && !dia2[curRow - curCol + n - 1];
    }
    
    public void copyBoardToAns(int[][] board){
        List<String> res = new LinkedList<>();
        for(int i = 0; i < n; i++){
            String row = "";
            for(int j = 0; j < n; j++){
                if(board[i][j] == 1){
                    row += "Q";
                }else{
                    row += ".";
                }
            }
            res.add(row);
        }
        ans.add(res);
    }
}
