class Solution {
    int m, n;
    vector<int> dx{-1, 0, 1, 0};
    vector<int> dy{0, 1, 0, -1};
public:
    int countBattleships(vector<vector<char>>& board) {
        
        int cnt = 0;
        m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == 'X')
                    cnt++, helper(board, i, j);
        
        return cnt;
    }
    
    void helper(vector<vector<char>> &board, int i, int j)
    {
        board[i][j] = '.';
        for(int k = 0; k < dx.size(); k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && y >= 0 && x < m && y < n && board[x][y] == 'X')
                helper(board, x, y);
        }
    }
};
