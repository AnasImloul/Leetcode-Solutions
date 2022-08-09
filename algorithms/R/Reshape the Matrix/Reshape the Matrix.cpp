class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if(m*n != r*c)
            return mat;
        vector<vector<int>> res(r, vector<int>(c));
        
        int k = 0, l = 0;
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) {
                res[k][l++] = mat[i][j]; 
                if(l == c) k++,l = 0;
            }
                
        return res;
    }
};
