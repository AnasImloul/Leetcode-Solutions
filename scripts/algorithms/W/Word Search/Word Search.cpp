class Solution {
public:
    bool solve(int i,int j,int &m,int &n,vector<vector<char>> &board,string &str,int s){
        if(s>=str.length()){
            return true;
        }
        if(i<0||j<0||i>=m||j>=n||board[i][j]=='#'){
            return false;
        }
        char c = board[i][j];
        board[i][j] = '#';
        bool a = false;
        if(c==str[s])
        a = solve(i+1,j,m,n,board,str,s+1)||solve(i-1,j,m,n,board,str,s+1)||solve(i,j-1,m,n,board,str,s+1) ||  solve(i,j+1,m,n,board,str,s+1);
        board[i][j] = c;
        return a;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int i,j,m=board.size(),n=board[0].size();
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(board[i][j]==word[0] && solve(i,j,m,n,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};