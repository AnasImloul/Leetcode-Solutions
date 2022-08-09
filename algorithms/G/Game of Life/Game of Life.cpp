// Idea: Encode the value into 2-bit value, the first bit is the value of next state, and the second bit is the value of current state
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                encode(board, i, j);
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                board[i][j] >>= 1;
            }
        }
        
    }
    void encode(vector<vector<int>>& board, int row, int col) {
        int ones = 0;
        int zeros = 0;
        int m = board.size();
        int n = board[0].size();
        int cur = board[row][col];
        if (row >= 1 && col >= 1) {
            ones += (board[row - 1][col - 1] & 1);
            zeros += !(board[row - 1][col - 1] & 1);
        }
        if (row >= 1) {
            ones += (board[row - 1][col] & 1);
            zeros += !(board[row - 1][col] & 1);
        }
        if (row >= 1 && col < n - 1) {
            ones += (board[row - 1][col + 1] & 1);
            zeros += !(board[row - 1][col + 1] & 1);
        }
        if (col < n - 1) {
            ones += (board[row][col + 1] & 1);
            zeros += !(board[row][col + 1] & 1);
        }
        if (row < m - 1 && col < n - 1) {
            ones += (board[row + 1][col + 1] & 1);
            zeros += !(board[row + 1][col + 1] & 1);
        }
        if (row < m - 1) {
            ones += (board[row + 1][col] & 1);
            zeros += !(board[row + 1][col] & 1);
        }
        if (row < m - 1 && col >= 1) {
            ones += (board[row + 1][col - 1] & 1);
            zeros += !(board[row + 1][col - 1] & 1);
        }
        if (col >= 1) {
            ones += (board[row][col - 1] & 1);
            zeros += !(board[row][col - 1] & 1);
        }
        if (ones < 2 && cur == 1) {
            cur += 0 << 1;
        } else if (ones >= 2 && ones <= 3 && cur == 1) {
            cur += 1 << 1;
        } else if (ones > 3 && cur == 1) {
            cur += 0 << 1;
        } else if (ones == 3 && cur == 0) {
            cur += 1 << 1;
        } else {
            cur += cur << 1;
        }
        board[row][col] = cur;
    }
};
