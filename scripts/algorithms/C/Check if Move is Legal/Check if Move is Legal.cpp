class Solution {
public:
    bool inBoard(vector<vector<char>>& board, int x, int y) {
        return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
    }
    
    bool isLegal(vector<vector<char>>& board, int x, int y, char color) {
        if (color == 'B') return board[x][y] == 'W';
        if (color == 'W') return board[x][y] == 'B';
        return false;
    }
    
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        vector<int> dir_x = {0, 0, 1, 1, 1, -1, -1, -1}, dir_y = {1, -1, 1, -1, 0, 1, -1, 0};
        for (int i = 0; i < 8; i++) {
            int x = rMove + dir_x[i], y = cMove + dir_y[i], count = 0;
            while (inBoard(board, x, y) && isLegal(board, x, y, color)) {
                x += dir_x[i], y += dir_y[i];
                count++;
            }
            if (inBoard(board, x, y) && board[x][y] == color && count > 0) return true;
        }
        return false;
    }
};
