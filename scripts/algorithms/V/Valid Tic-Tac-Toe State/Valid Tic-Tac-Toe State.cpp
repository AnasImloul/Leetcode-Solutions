class Solution {
public:
    
    bool win(vector<string> board, char player, int size){
        int row_win=0, col_win=0, diagonal_win=0, rev_diagonal_win=0;
        
        for(int i=0;i<3;i++){
            
            row_win=0; 
            col_win=0;
            
            for(int j=0;j<3;j++){
                
                if(player == board[i][j]){
                    row_win++; 
                    if(row_win == 3)
                        return 1;
                }
                
                if(player == board[j][i]){
                    col_win++;
                    if(col_win == 3)
                        return 1;
                }
                    
                if(i==j && player==board[i][j]){
                    diagonal_win++;
                }
                
                if(i+j == size-1 && player==board[i][j]){
                    rev_diagonal_win++;
                }
                    
            }
        }
        
        if(diagonal_win==3 || rev_diagonal_win==3)
            return 1;
        
        return 0;
    }
    
    bool validTicTacToe(vector<string>& board) {
        int count_x=0, count_o=0, size = board.size();
        for(auto i:board){
            for(auto j:i){
                if(j=='X') count_x++;
                else if(j=='O') count_o++;
            }
        }
        if(count_o>count_x || count_x-count_o>=2)
            return false;
        if(count_x>=3 && count_x==count_o && win(board, 'X', size))
            return false;
        if(count_o>=3 && count_x>count_o && win(board, 'O', size))
            return false;
        
        return true;
    }
};
