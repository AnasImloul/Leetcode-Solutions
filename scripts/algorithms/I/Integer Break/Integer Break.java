// Runtime: 0 ms (Top 100.0%) | Memory: 40.80 MB (Top 7.7%)

class Solution {
    public int integerBreak(int n) {
        if (n <= 1) {
            return 0;
        }
        int[] memo = new int[n + 1];
        return maxProduct(n, memo);
    }
    
    private int maxProduct(int n, int[] memo) {
        if (n == 2) {
            return 1;
        }
        if (memo[n] != 0) {
            return memo[n];
        }
        int max = 0;
        for (int i = 1; i < n; i++) {
            max = Math.max(max, Math.max(i * (n - i), i * maxProduct(n - i, memo)));
        }
        memo[n] = max;
        return max;
    }
}
