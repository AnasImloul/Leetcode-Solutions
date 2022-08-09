// Champagne Tower
// Leetcode: https://leetcode.com/problems/champagne-tower/

class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        if (poured == 0) return 0;
        double[] memo = new double[101];
        memo[0] = poured;
        for (int i=0; i<100; i++) {
            for (int j=i; j>=0; j--) {
                if (memo[j] > 1) {
                    if (i == query_row && j == query_glass) return 1;
                    double val = (memo[j] - 1) / 2;
                    memo[j+1] += val;
                    memo[j] = val;
                } else {
                    if (i == query_row && j == query_glass) return memo[query_glass];
                    memo[j+1] += 0;
                    memo[j] = 0;
                }
            }
        }
        return memo[query_glass];
    }
}
