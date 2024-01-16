// Runtime: 19 ms (Top 90.12%) | Memory: 45.20 MB (Top 64.2%)

class Solution {
    int mod = (1000000007);

    public int countTexts(String pressedKeys) {
        int[] key = new int[] { 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };
        int n = pressedKeys.length();
        int[] dp = new int[n + 1];
        dp[n] = 1;

        for (int ind = n - 1; ind >= 0; ind--) {
            int count = 0;
            int num = pressedKeys.charAt(ind) - '0';
            int rep = key[num];
            for (int i = 0; i < rep && ind + i < pressedKeys.length() && pressedKeys.charAt(ind) == pressedKeys.charAt(ind + i); i++) {
                count += dp[ind+i+1];
                count %= mod;
            }
             dp[ind] = count;
        }
        return dp[0];
    }
}
