// Runtime: 512 ms (Top 28.16%) | Memory: 59.7 MB (Top 88.82%)
class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n; j++){
                if(board[i][j] != '#'){
                    if(valid(board, i-1, j) && check(board, word, i, j, 0, true, 1)) return true;
                    if(valid(board, i+1, j) && check(board, word, i, j, 0, true, -1)) return true;
                    if(valid(board, i, j-1) && check(board, word, i, j, 0, false, 1)) return true;
                    if(valid(board, i, j+1) && check(board, word, i, j, 0, false, -1)) return true;
                }
            }
        }
        return false;
    }

    bool check(vector<vector<char>>& board, string &word, int x, int y, int pos, bool vertical, int inc){
        if(pos == word.size()){
            if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return true;
            return board[x][y] == '#';
        }
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false;
        if(board[x][y] == '#') return false;
        if(board[x][y] != ' ' && board[x][y] != word[pos]) return false;
        int newx = x + vertical * inc;
        int newy = y + (!vertical) * inc;
        return check(board, word, newx, newy, pos+1, vertical, inc);
    }

    bool valid(vector<vector<char>>& board, int x, int y){
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return true;
        return board[x][y] == '#';
    }
};