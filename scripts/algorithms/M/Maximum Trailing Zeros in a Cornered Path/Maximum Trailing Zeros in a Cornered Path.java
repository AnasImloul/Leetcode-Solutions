// Runtime: 84 ms (Top 75.61%) | Memory: 82.50 MB (Top 26.83%)

class Solution {
    public int maxTrailingZeros(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] two = new int[m][n];
        int[][] five = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                two[i][j] = getFactorNum(grid[i][j], 2);
                five[i][j] = getFactorNum(grid[i][j], 5);
            }
        }
        
        int[][] left2 = new int[m][n];
        int[][] left5 = new int[m][n];
        for (int i = 0; i < m; ++i) {
            int sum2 = 0;
            int sum5 = 0;
            for (int j = 0; j < n; ++j) {
                sum2 += two[i][j];
                sum5 += five[i][j];
                left2[i][j] = sum2;
                left5[i][j] = sum5;
            }
        }
        
        int[][] right2 = new int[m][n];
        int[][] right5 = new int[m][n];
        for (int i = 0; i < m; ++i) {
            int sum2 = 0;
            int sum5 = 0;
            for (int j = n - 1; j >= 0; --j) {
                sum2 += two[i][j];
                sum5 += five[i][j];
                right2[i][j] = sum2;
                right5[i][j] = sum5;
            }
        }
        
        int[][] up2 = new int[m][n];
        int[][] up5 = new int[m][n];
        for (int j = 0; j < n; ++j) {
            int sum2 = 0;
            int sum5 = 0;
            for (int i = 0; i < m; ++i) {
                sum2 += two[i][j];
                sum5 += five[i][j];
                up2[i][j] = sum2;
                up5[i][j] = sum5;
            }
        }
        
        int[][] down2 = new int[m][n];
        int[][] down5 = new int[m][n];
        for (int j = 0; j < n; ++j) {
            int sum2 = 0;
            int sum5 = 0;
            for (int i = m - 1; i >= 0; --i) {
                sum2 += two[i][j];
                sum5 += five[i][j];
                down2[i][j] = sum2;
                down5[i][j] = sum5;
            }
        }
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // left-up
                if (i != 0 || j != 0) {
                    int cur = Math.min(left2[i][j] + up2[i][j] - two[i][j], left5[i][j] + up5[i][j] - five[i][j]);
                    res = Math.max(res, cur);
                }
                
                // up-right
                if (i != 0 || j != n - 1) {
                    int cur = Math.min(right2[i][j] + up2[i][j] - two[i][j], right5[i][j] + up5[i][j] - five[i][j]);
                    res = Math.max(res, cur);
                }
                
                // right-down
                if (i != m - 1 || j != n - 1) {
                    int cur = Math.min(right2[i][j] + down2[i][j] - two[i][j], right5[i][j] + down5[i][j] - five[i][j]);
                    res = Math.max(res, cur);
                }
                
                // down-left
                if (i != m - 1 || j != 0) {
                    int cur = Math.min(left2[i][j] + down2[i][j] - two[i][j], left5[i][j] + down5[i][j] - five[i][j]);
                    res = Math.max(res, cur);
                }
            }
        }
        return res;
    }
    
    private int getFactorNum(int input, int factor) {
        int res = 0;
        while (input != 0 && input % factor == 0) {
            ++res;
            input /= factor;
        }
        return res;
    }
}
