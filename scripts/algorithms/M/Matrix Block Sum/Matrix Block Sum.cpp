class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pref(n+1, vector<int>(m+1, 0));
        // Calculating prefix sum
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                // note that while counting for [i-1][j] and [i][j-1];
                // pref[i-1][j-1] will be added twice. So we reduce it once.
                pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }

        // Find the sum of the elements specified in the K-block
        vector<vector<int>> res(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // checking for all pairs to be in bounds.
                int r1 = max(0, i-k);
                int c1 = max(0, j-k);
                int r2 = min(n-1, i+k);
                int c2 = min(m-1, j+k);
                // finding res[i][j] = bottom right - bottom left - top right + top left
                res[i][j] = pref[r2+1][c2+1] - pref[r2+1][c1] - pref[r1][c2+1] + pref[r1][c1];
            }
        }

        return res;

    }
};