class Solution {
    const int inf = 1e9;
    void transpose(vector<vector<int>>& board) {
        const int n = board.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                swap(board[i][j], board[j][i]);
    }
    
    bool isSame(vector<int> &r1, vector<int>& r2) {
        const int n = r1.size();
        for (int i = 0; i < n; i++)
            if (r1[i] != r2[i])
                return false;
        return true;
    }
    
    bool isOpposite(vector<int> &r1, vector<int>& r2) {
        const int n = r1.size();
        for (int i = 0; i < n; i++)
            if (r1[i] == r2[i])
                return false;
        return true;
    }
    
    int getSteps(vector<vector<int>> &&confusionMatrix) {
        int steps = inf;
        
        if (confusionMatrix[0][1] == confusionMatrix[1][0])
            steps = confusionMatrix[0][1];
        
        if (confusionMatrix[0][0] == confusionMatrix[1][1])
            steps = min(steps, confusionMatrix[0][0]);
        
        return steps;
    }
    
    vector<vector<int>> getConfusionMatrix(vector<int>& rowType) {
        const int n = rowType.size();
        vector<vector<int>> confusionMatrix(2, vector<int>(2, 0));
        for (int i = 0; i < n; i++)
            confusionMatrix[rowType[i]][i & 1]++;
        return confusionMatrix;
    }
    
    int solve1d(vector<int> &arr) {
        return getSteps(getConfusionMatrix(arr));
    }
    
    int makeColumnsAlternating(vector<vector<int>>& board) {
        const int n = board.size();
        vector<int> rowType(n, 0);
        for (int i = 1; i < n; i++)
            if (isOpposite(board[0], board[i]))
                rowType[i] = 1;
            else if (!isSame(board[0], board[i]))
                return inf;
        return solve1d(rowType);
    }
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int steps = makeColumnsAlternating(board);
        transpose(board);
        steps += makeColumnsAlternating(board);
        if (steps >= inf)
            return -1;
        return steps;
    }
};
