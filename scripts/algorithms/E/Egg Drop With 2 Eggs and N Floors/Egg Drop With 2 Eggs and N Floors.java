// Runtime: 74 ms (Top 32.31%) | Memory: 42.5 MB (Top 12.73%)
class Solution {
    public int twoEggDrop(int n) {
        int egg = 2; // hard coded to 2 eggs for this problem
        int[][] dp = new int[n+1][egg+1];
        return eggDrop(n, egg, dp);
    }

    int eggDrop(int n, int egg, int[][] dp) {
        if(n <= 2 || egg == 1) return n;
        if(dp[n][egg] != 0) return dp[n][egg];
        int min = n; // when you drop at each floor starting from 1
        for(int i = 1; i < n; i++) {
            int eggBreak = 1 + eggDrop(i-1, egg-1, dp); // drops needed if egg breaks at this floor
            int noEggBreak = 1 + eggDrop(n-i, egg, dp); // drops needed if egg does not break at this floor
            int moves = Math.max(eggBreak, noEggBreak); // since we want certain moves for n floor take max
            min = Math.min(min, moves);
        }
        dp[n][egg] = min;
        return min;
    }
}