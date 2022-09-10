// Runtime: 0 ms (Top 100.00%) | Memory: 41.3 MB (Top 62.26%)
class Solution {
    public int numRookCaptures(char[][] board) {
        int ans = 0;

        int row = 0;
        int col = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    row = i;
                    col = j;
                    break;
                }
            }
        }

        int j = col;
        while (j >= 0) {
            if (board[row][j] == 'B') {
                break;
            } else if (board[row][j] == 'p') {
                ans++;
                break;
            }

            j--;
        }

        j = col;
        while (j <= board[0].length - 1) {
            if (board[row][j] == 'B') {
                break;
            } else if (board[row][j] == 'p') {
                ans++;
                break;
            }

            j++;
        }

        int i = row;
        while (i <= board.length - 1) {
            if (board[i][col] == 'B') {
                break;
            } else if (board[i][col] == 'p') {
                ans++;
                break;
            }

            i++;
        }

        i = row;
        while (i >= 0) {
            if (board[i][col] == 'B') {
                break;
            } else if (board[i][col] == 'p') {
                ans++;
                break;
            }

            i--;
        }

        return ans;
    }
}