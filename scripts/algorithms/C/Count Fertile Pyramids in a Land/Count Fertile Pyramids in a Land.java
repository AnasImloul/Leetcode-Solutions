class Solution {
    public int countPyramids(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] rev = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) rev[m - i - 1][j] = grid[i][j];
        }
        return cal(grid) + cal(rev);
    }
    private int cal(int[][] grid) {
        int m = grid.length, n = grid[0].length, res = 0;
        for (int i = 1; i < m; ++i) {
            for (int j = 0, cnt = 0; j < n; ++j) {
                if (0 != grid[i][j]) cnt++;
                else cnt = 0;
                if (0 == cnt || 0 == j) continue;
                grid[i][j] = Math.min(grid[i - 1][j - 1] + 1, (cnt + 1) >> 1);
                res += grid[i][j] - 1;
            }
        }
        return res;
    }
}
