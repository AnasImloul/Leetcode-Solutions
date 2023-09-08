// Runtime: 210 ms (Top 41.6%) | Memory: 104.25 MB (Top 18.7%)

class Solution {
    Integer[][][] memo;
    int n;
    public int numberOfSets(int n, int k) {
        this.n = n;
        this.memo = new Integer[n+1][k+1][2];
        return dp(0, k, 1);
    }
    int dp(int i, int k, int isStart) {
        if (memo[i][k][isStart] != null) return memo[i][k][isStart];
        if (k == 0) return 1; // Found a way to draw k valid segments
        if (i == n) return 0; // Reach end of points

        int ans = dp(i+1, k, isStart); // Skip ith point
        if (isStart == 1)
            ans += dp(i+1, k, 0); // Take ith point as start
        else
            ans += dp(i, k-1, 1); // Take ith point as end

        return memo[i][k][isStart] = ans % 1_000_000_007;
    }
}