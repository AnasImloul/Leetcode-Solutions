// Runtime: 149 ms (Top 22.45%) | Memory: 56.7 MB (Top 20.41%)
class Solution {
    long[][][] dp;
    int mod = 1_000_000_007;
    public int dieSimulator(int n, int[] rollMax) {
        dp = new long[n + 1][7][16];
        for(long[][] row: dp)
            for(long[] col: row)
                Arrays.fill(col, -1);

        return (int)helper(n, 0, 0, rollMax, 0);
    }

    private long helper(int n, int dice, int prev, int[] rollMax, int runs)
    {
        if(n == dice)
            return 1;

        if(dp[dice][prev][runs] != -1)
            return dp[dice][prev][runs];

        long ans = 0;
        int[] temp = rollMax;
        for(int i = 1; i <= 6; i++)
        {
            if(prev != 0 && i == prev && rollMax[i-1] <= runs)
                continue;
            if(i == prev)
                ans = (ans + helper(n, dice + 1, i, rollMax, runs + 1)) % mod;
            else
                ans = (ans + helper(n, dice + 1, i, rollMax, 1)) % mod;
        }

        dp[dice][prev][runs] = ans;
        return ans;
    }
}