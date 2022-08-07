class Solution {
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; ++i) {
            HashSet<Character> h = new HashSet<>();
            HashSet<Character> h2 = new HashSet<>();
            for (int j = 0; j < 9; ++j) {
                //if there is a reoccurence we return false immediately, else we add it to our hashset if it's not empty square(1x1) (empty squares are represented with '.')
                if (h.contains(board[i][j])) return false;//row wise traversal
                //Don't forget to use single quotes, because it's a char matrix
                if (board[i][j] != '.') h.add(board[i][j]);//row wise traversal
                if (h2.contains(board[j][i])) return false;//column wise traversal
                if (board[j][i] != '.') h2.add(board[j][i]);//column wise traversal
            }
        }
        HashSet<Character> h1 = new HashSet<>();//hx, where x is left to right, top to bottom numbers of small squares
        HashSet<Character> h2 = new HashSet<>();
        HashSet<Character> h3 = new HashSet<>();
        HashSet<Character> h4 = new HashSet<>();
        HashSet<Character> h5 = new HashSet<>();
        HashSet<Character> h6 = new HashSet<>();
        HashSet<Character> h7 = new HashSet<>();
        HashSet<Character> h8 = new HashSet<>();
        HashSet<Character> h9 = new HashSet<>();
        
        for (int i = 0; i < 3; ++i) {//first small square
            for (int j = 0; j < 3; ++j) {
                if (h1.contains(board[i][j])) return false;
                if (board[i][j] != '.') h1.add(board[i][j]);
            }
        }
        h1 = null;//we don't need h1 anymore, so lets make it null and hope garbage collector to collect it
        for (int i = 0; i < 3; ++i) {
            for (int j = 3; j < 6; ++j) {
                if (h2.contains(board[i][j])) return false;
                if (board[i][j] != '.') h2.add(board[i][j]);
            }
        }
        h2 = null;
        for (int i = 0; i < 3; ++i) {
            for (int j = 6; j < 9; ++j) {
                if (h3.contains(board[i][j])) return false;
                if (board[i][j] != '.') h3.add(board[i][j]);
            }
        }
        h3 = null;
        for (int i = 3; i < 6; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (h4.contains(board[i][j])) return false;
                if (board[i][j] != '.') h4.add(board[i][j]);
            }
        }
        h4 = null;
        for (int i = 3; i < 6; ++i) {
            for (int j = 3; j < 6; ++j) {
                if (h5.contains(board[i][j])) return false;
                if (board[i][j] != '.') h5.add(board[i][j]);
            }
        }
        h5 = null;
        for (int i = 3; i < 6; ++i) {
            for (int j = 6; j < 9; ++j) {
                if (h6.contains(board[i][j])) return false;
                if (board[i][j] != '.') h6.add(board[i][j]);
            }
        }
        h6 = null;
        for (int i = 6; i < 9; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (h7.contains(board[i][j])) return false;
                if (board[i][j] != '.') h7.add(board[i][j]);
            }
        }
        h7 = null;
        for (int i = 6; i < 9; ++i) {
            for (int j = 3; j < 6; ++j) {
                if (h8.contains(board[i][j])) return false;
                if (board[i][j] != '.') h8.add(board[i][j]);
            }
        }
        h8 = null;
        for (int i = 6; i < 9; ++i) {
            for (int j = 6; j < 9; ++j) {
                if (h9.contains(board[i][j])) return false;
                if (board[i][j] != '.') h9.add(board[i][j]);
            }
        }
        h9 = null;
        
        return true;
    }
}
