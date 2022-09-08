// Runtime: 141 ms (Top 88.88%) | Memory: 136.6 MB (Top 5.23%)
class NumMatrix {

    int mat[][];
    public NumMatrix(int[][] matrix) {
        mat = matrix;
        int rows = mat.length;
        int cols = mat[0].length;

        for(int i = 0; i< rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(i > 0) mat[i][j] += mat[i-1][j];
                if(j > 0) mat[i][j] += mat[i][j-1];
                if(i>0 && j > 0) mat[i][j] -= mat[i-1][j-1];
            }
        }

    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int res = mat[row2][col2];
        if(row1 > 0) res -= mat[row1-1][col2];
        if(col1 > 0) res -= mat[row2][col1-1];
        if(row1> 0 && col1 > 0) res += mat[row1-1][col1-1];

        return res;
    }
}