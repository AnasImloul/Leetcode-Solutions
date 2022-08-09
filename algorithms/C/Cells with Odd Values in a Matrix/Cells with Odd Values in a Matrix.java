// --------------------- Solution 1 ---------------------
class Solution {
    public int oddCells(int m, int n, int[][] indices) {
        int[][] matrix = new int[m][n];
        
        for(int i = 0; i < indices.length; i++) {
            int row = indices[i][0];
            int col = indices[i][1];
            
            for(int j = 0; j < n; j++) {
                matrix[row][j]++;
            }
            for(int j = 0; j < m; j++) {
                matrix[j][col]++;
            }
        }
        
        int counter = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] % 2 != 0) {
                    counter++;
                }
            }
        }
        
        return counter;
    }
}

// --------------------- Solution 2 ---------------------
class Solution {
    public int oddCells(int m, int n, int[][] indices) {
        int[] row = new int[m];
        int[] col = new int[n];
        
        for(int i = 0; i < indices.length; i++) {
            row[indices[i][0]]++;
            col[indices[i][1]]++;
        }
        
        int counter = 0;
        for(int i : row) {
            for(int j : col) {
                counter += (i + j) % 2 == 0 ? 0 : 1;
            }
        }
        
        return counter;
    }
}
