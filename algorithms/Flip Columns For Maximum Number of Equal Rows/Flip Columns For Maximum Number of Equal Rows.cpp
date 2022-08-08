class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            vector<int> temp(n);
            for(int j = 0; j < n; j++)
            temp[j] = !matrix[i][j];
            int count = 0;
            for(int j = i; j < m; j++){       
                
                if((matrix[i] == matrix[j]) || (temp == matrix[j]))
                    count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
