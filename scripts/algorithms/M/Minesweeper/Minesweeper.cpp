// Runtime: 56 ms (Top 19.17%) | Memory: 11.7 MB (Top 93.43%)
class Solution {
public:
    int m, n ;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X' ;
            return board ;
        }
        else{
            m = board.size(), n = board[0].size() ;
            dfs(click[0], click[1], board) ;
        }
        return board ;
    }

    const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
    const int dy[8] = {0, -1, 0, 1, 1, -1, -1, 1};
    void dfs(int cr, int cc, vector<vector<char>> &board){
        int count = 0 ;
        for(int i = 0 ; i < 8 ; i++){
            int nr = cr + dx[i], nc = cc + dy[i] ;
            if(nr<0 || nr>=m || nc<0 || nc >=n || board[nr][nc]!='M') continue;
            count++ ;
        }

        if(count!=0){
            board[cr][cc] = '0'+count ;
            return ;
        }else{
            board[cr][cc] = 'B' ;
            for(int i = 0 ; i < 8 ; i++){
                int nr = cr + dx[i], nc = cc + dy[i] ;
                if(nr<0 || nr>=m || nc<0 || nc >=n || board[nr][nc]!='E') continue;
                dfs(nr, nc, board) ;
            }
        }
    }
};