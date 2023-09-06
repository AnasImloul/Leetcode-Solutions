// Runtime: 0 ms (Top 100.0%) | Memory: 39.00 MB (Top 80.9%)

class Solution {
    public int climbStairs(int n) {
        int[] memo = new int[n + 1];
        return calculateWays(n, memo);
    }
    
    private int calculateWays(int n, int[] memo) {
        if (n == 1 || n == 2) {
            return n;
        }
        
        if (memo[n] != 0) {
            return memo[n];
        }
        
        memo[n] = calculateWays(n - 1, memo) + calculateWays(n - 2, memo);
        return memo[n];
    }
}