// Runtime: 0 ms (Top 100.00%) | Memory: 42.1 MB (Top 73.63%)
class Solution {
    public void gameOfLife(int[][] board) {
        int m = board.length, n = board[0].length;
        int[][] next = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                next[i][j] = nextState(board, i, j, m, n);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = next[i][j];
            }
        }
    }

    public int nextState(int[][] board, int i, int j, int m, int n) {
        int ones = 0;
        for (int x = -1; x <=1; x++) {
            for (int y = -1; y <= 1; y++) {
                if (x == 0 && y == 0) {
                    continue;
                }
                int a = i + x, b = j + y;
                if (a >= 0 && a < m) {
                    if (b >= 0 && b < n) {
                        ones += board[a][b];
                    }
                }
            }
        }
        if (board[i][j] == 0) {
            return ones == 3 ? 1 : 0;
        } else {
            if (ones == 2 || ones == 3) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}