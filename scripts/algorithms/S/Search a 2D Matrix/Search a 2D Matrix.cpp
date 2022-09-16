// Runtime: 4 ms (Top 79.96%) | Memory: 9.6 MB (Top 51.36%)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i ++) {
            if(matrix[i][0] > target) return false;
            for(int j = 0; j < matrix[i].size(); j ++) {
                if(matrix[i][j] == target) return true;
                else if(matrix[i][j] > target) break;
            }
        }
        return false;
    }
};