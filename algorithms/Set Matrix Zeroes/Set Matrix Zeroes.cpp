class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int rowFlag = 0, colFlag = 0;
        
        for(int i = 0; i < rows; i++){
            if(matrix[i][0] == 0){
                rowFlag = 1;
                break;
            }
        }
        
        for(int i = 0; i < cols; i++){
            if(matrix[0][i] == 0){
                colFlag = 1;
                break;
            }
        }
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(rowFlag){
            for(int i = 0; i < rows; i++){
                matrix[i][0] = 0;
            }
        }
        
        if(colFlag){
            for(int i = 0; i < cols; i++){
                matrix[0][i] = 0;
            }
        }
    }
};
