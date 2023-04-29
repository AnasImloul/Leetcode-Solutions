class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.size()* mat[0].size()!= r * c) {
            return mat;
        } 
        vector<vector<int>>v(r,vector<int>(c));
        int k = 0;
        int l = 0;

        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                if(l == v[0].size()) {
                    l = 0;
                    k++;
                }

                v[k][l++] = mat[i][j];
            }
        }
        return v;
    }
};