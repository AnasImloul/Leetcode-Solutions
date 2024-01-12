// Runtime: 20 ms (Top 84.0%) | Memory: 56.70 MB (Top 5.33%)

class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int[][] res = new int[n][n];
        for (var q : queries) {
            int r0 = q[0], c0 = q[1], r1 = q[2]+1, c1 = q[3]+1;
            for (int i = r0; i < r1; i++) {
                res[i][c0]++;
                if (c1 < n) res[i][c1]--;
            }
        }

        for (var row : res)
            for (int j = 1; j < n; j++)
                row[j] += row[j-1];

        return res;
    }
}
