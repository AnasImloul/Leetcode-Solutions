class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> r,c;
        int i,j,m = matrix.size(),n = matrix[0].size();
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(!matrix[i][j]){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(auto &i: r){
            for(j = 0; j < n; j++){
                matrix[i][j] = 0;
            }
        }for(auto &i: c){
            for(j = 0; j < m; j++){
                matrix[j][i] = 0;
            }
        }
    }
};