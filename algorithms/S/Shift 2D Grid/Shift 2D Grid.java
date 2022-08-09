class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        // just bruteforce??? O(i*j*k)
        // instead we calculate the final position at once!
        
        int m = grid.length;  // row
        int n = grid[0].length;  // column
        
        int[][] arr = new int[m][n];
        
        // Since moving m*n times will result in same matrix, we do this:
        k = k % (m*n);
        
        // Then we move each element
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // for calculating column, it back to the original position
                // every n steps
                int column = (j + k) % n;
                
                // for calculating row, we move to the next row each time
                // it exceed the last element on the current row.
                // For example when 2 moves k=5 steps it turns to the (+2) row.
                // Thus it's original row + ((original column + steps) / n)
                // But if 2 moves k=8 steps it turns to the (0,0),
                // and row + ((original column + steps) / n) gives 0+(9/3)=3 (out of bounds)
                // so we'll need to % number of rows to get 0. (circle back)
                int row = (i + ((j + k) / n)) % m;
                arr[row][column] = grid[i][j];
            }
        }
        return (List) Arrays.asList(arr);
    }
}
