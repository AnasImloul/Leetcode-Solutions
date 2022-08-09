class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        
        if (r * c != mat.length * mat[0].length) {
            return mat;
        }
		
        int[][] ans = new int[r][c];
        
        int i = 0;
        int j = 0;
        
        for(int k = 0; k < mat.length; k++) {
            for(int l = 0; l < mat[0].length; l++) {
                if (j == c) {
                    i++;
                    j = 0;
                }
                ans[i][j++] = mat[k][l];
            }
        }
        return ans;
    }
}
