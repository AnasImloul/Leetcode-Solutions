// Runtime: 6 ms (Top 48.8%) | Memory: 6.26 MB (Top 47.9%)

class Solution {
public:
    bool isSafe(int row , int col , vector<vector<int>> &board , int n){
    //check for same row
    int x = row;
    int y = col;
    
    while(y >= 0){
        if(board[x][y] == 1)
            return false;
        y--;
    }
    
    //no need to check for columns as we are adding one queen in one column
    
    //check for diagonals
    //check for North West(NW) diagonal
    x = row;
    y = col;
    
    while(x>=0 && y >= 0){
        if(board[x][y] == 1)
            return false;
        y--;
        x--;
    }
    
    //check for SW diagonal
    x = row;
    y = col;
    
    while(x<n && y >= 0){
        if(board[x][y] == 1)
            return false;
        y--;
        x++;
    }
    //no need to check for NE and SE diagonals as queen hasn't been added to the right.
    return true;
}

    void solve(int col , vector<vector<int>> &ans , vector<vector<int>> &board , int n , int &count){
    //base case
    if(col == n){
        count++;
        return ;
    }
    
    //solve for 1 column, rest recursion will take care
    for(int row = 0 ; row < n ; row++){
        if(isSafe(row,col,board,n)){
            board[row][col] = 1;
            solve(col+1 , ans , board , n , count);
            //backtrack
            board[row][col] = 0;
        }
    }
}

    int totalNQueens(int n) {
        vector<vector<int>> board(n , vector<int>(n,0));
        vector<vector<int>> ans;
        int count = 0;
        
        solve(0 , ans , board , n , count);
        return count;
    }
};