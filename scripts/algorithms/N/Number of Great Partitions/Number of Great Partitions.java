// Runtime: 4 ms (Top 100.0%) | Memory: 41.60 MB (Top 97.78%)

class Solution {
    static int mod = (int) 1e9 + 7;
    public int countPartitions(int[] nums, int k) {
        long sum = 0;
        for (int i : nums) sum += i;
        if (sum < k * 2) return 0;
        int[] dp = new int[k];
        dp[0] = 1;
        for (int i : nums) {
            for (int j = k - 1; i <= j; --j) dp[j] = (dp[j] + dp[j - i]) % mod;
        }
        int less = 0;
        for (int i = 0; i < k; ++i) less = (less + dp[i]) % mod;
        return ((pow(nums.length) - (less << 1)) % mod + mod) % mod;
    }
    private int pow(int n) {
        long res = 1, m = 2;
        while (0 != n) {
            if (1 == (n & 1)) res = res * m % mod;
            n >>= 1;
            m = m * m % mod;
        }
        return (int) res;
    }
}
