class Solution {
    public boolean isValidSudoku(char[][] board) {
        HashSet<String> set = new HashSet<>();
        
        for(int i = 0;i<board.length;i++) {
            for(int j = 0; j < board[0].length;j++) {
                if(board[i][j] != '.') {
                    if(set.contains("row"+i+board[i][j]) || set.contains("col"+j+board[i][j])) {
                        return false;
                    }
                    set.add("row"+i+board[i][j]);
                    set.add("col"+j+board[i][j]);
                    if(set.contains("box"+(i/3)+(j/3)+board[i][j])) {
                        return false;
                    }
                    set.add("box"+(i/3)+(j/3)+board[i][j]);
                }
            }
        }
        return true;
    }
}
