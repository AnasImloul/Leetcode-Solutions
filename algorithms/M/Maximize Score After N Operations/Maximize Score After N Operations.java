class Solution {
    public int maxScore(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> gcdVal = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                gcdVal.put((1 << i) + (1 << j), gcd(nums[i], nums[j]));
            }
        }
        
        int[] dp = new int[1 << n];
        
        for (int i = 0; i < (1 << n); ++i) {
            int bits = Integer.bitCount(i); // how many numbers are used
            if (bits % 2 != 0) // odd numbers, skip it
                continue;
            for (int k : gcdVal.keySet()) {
                if ((k & i) != 0) // overlapping used numbers
                    continue;
                dp[i ^ k] = Math.max(dp[i ^ k], dp[i] + gcdVal.get(k) * (bits / 2 + 1));
            }
        }
        
        return dp[(1 << n) - 1];
    }
    
    public int gcd(int a, int b) {
        if (b == 0)   
            return a;     
        return gcd(b, a % b);   
    }
}

// Time: O(2^n * n^2)
// Space: O(2 ^ n)
