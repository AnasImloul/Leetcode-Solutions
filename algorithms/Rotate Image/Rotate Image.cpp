class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int gap=1;
        for(int i=0;i<matrix.size();i++){
            
            for(int j=gap;j<matrix[i].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
            gap++;
        }
        
        for(int i=0;i<matrix.size();i++){
            
            int first=0;
            int last= matrix[i].size()-1;
            
            while(first<last){
                swap(matrix[i][first],matrix[i][last]);
                first++;
                last--;
                
            }
            
        }
        
    }
};
