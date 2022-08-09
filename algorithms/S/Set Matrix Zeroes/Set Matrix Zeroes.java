class Solution {
    public void setZeroes(int[][] matrix) {        
		if (matrix == null || matrix.length == 0 || matrix[0].length == 0)
			return;

		int row = matrix.length;
		int col = matrix[0].length;

		boolean firstColumnZero = false;
		boolean firstRowZero = false;

		// Check if first column should be made zero
		for (int i = 0; i < row; i++) {
			if (matrix[i][0] == 0) {
				firstColumnZero = true;
				break;
			}
		}

		// Check if first row should be made zero
		for (int i = 0; i < col; i++) {
			if (matrix[0][i] == 0) {
				firstRowZero = true;
				break;
			}
		}

		// Traverse the matrix excluding first row and column
		// If zero is found, update the same in first row and column

		for (int i = 1; i < row; i++) {
			for (int j = 1; j < col; j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		// Now traverse again and update
		for (int i = 1; i < row; i++) {
			for (int j = 1; j < col; j++) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}

		// Traverse and update first column
		if (firstColumnZero) {
			for (int i = 0; i < row; i++) {
				matrix[i][0] = 0;
			}
		}

		// Traverse and update first row
		if (firstRowZero) {
			for (int j = 0; j < col; j++) {
				matrix[0][j] = 0;
			}
		}

	
    }
}
