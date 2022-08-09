class Solution {
    public int countNegatives(int[][] grid) {
        int m = grid.length ;
        int n = grid[0].length ;
        int c = 0;
        int count = 0;
        int r = m-1;
        while( r >= 0 && c < n ) {
            if (grid[r][c] < 0 ) {
                r--;
                count += n - c;
            } else{
                c++;
            }
        }
        return count;
    }
}

