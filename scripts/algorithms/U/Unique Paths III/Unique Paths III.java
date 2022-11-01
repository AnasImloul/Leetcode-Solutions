// Runtime: 2 ms (Top 41.86%) | Memory: 42.7 MB (Top 13.82%)
class Solution {
    int walk = 0;
    public int uniquePathsIII(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    walk++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return ways(grid, i, j, m, n, 0);
                }
            }
        }
        return 0;
    }
    public int ways(int[][] grid, int cr, int cc, int m, int n, int count) {
        if (cr < 0 || cr == m || cc < 0 || cc == n || grid[cr][cc] == -1) {
            return 0;
        }
        if (grid[cr][cc] == 2) {
            if (count - 1 == walk) return 1;
            return 0;
        }
        grid[cr][cc] = -1;
        int ans = 0;
        int[] r = {0, 1, 0, -1};
        int[] c = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            ans += ways(grid, cr + r[i], cc + c[i], m, n, count + 1);
        }
        grid[cr][cc] = 0;
        return ans;
    }
}