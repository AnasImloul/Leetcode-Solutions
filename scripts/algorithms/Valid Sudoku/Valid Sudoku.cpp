class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // validate all rows
        int row[9][9] = {};
        for (int i=0; i<9; i++)
            for (int j=0; j<9; j++)
                if (board[i][j] != '.')
                    if (row[i][board[i][j]-'1'] != 1)
                        row[i][board[i][j]-'1'] = 1; // mark as seen
                    else 
                        return false;
        
        // validate all cols
        int col[9][9] = {};
        for (int i=0; i<9; i++)
            for (int j=0; j<9; j++)
                if (board[j][i] != '.')
                    if (col[board[j][i]-'1'][i] != 1)
                        col[board[j][i]-'1'][i] = 1; // mark as seen
                    else
                        return false;
        
        // validate all 3x3s   
        int box[3][3][9] = {};
        for (int i=0; i<9; i++) 
            for (int j=0; j<9; j++) 
                if (board[i][j] != '.') 
                    if (box[i/3][j/3][board[i][j]-'1'] != 1)
                        box[i/3][j/3][board[i][j]-'1'] = 1; // mark as seen
                    else
                        return false;
        
        return true;
    }
};