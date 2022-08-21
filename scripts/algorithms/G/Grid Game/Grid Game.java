// Runtime: 11 ms (Top 40.95%) | Memory: 94.7 MB (Top 51.18%)

class Solution {
    public long gridGame(int[][] grid) {
        int n = grid[0].length;
        long preRow1[] = new long[n];
        long preRow2[] = new long[n];

        preRow1[0] = grid[0][0];
        preRow2[0] = grid[1][0];

        for(int i = 1;i<n;i++){
            preRow1[i] += (long)preRow1[i-1] + (long)grid[0][i];
            preRow2[i] += (long)preRow2[i-1] + (long)grid[1][i];
        }

        long res = Long.MAX_VALUE;
        for(int i = 0;i<n;i++){
            long top = preRow1[n-1] - preRow1[i];
            long bottom = i == 0 ? 0 : preRow2[i-1];
            long temp = Math.max(top,bottom);
            res = Math.min(res,temp);
        }

        return res;
    }
}