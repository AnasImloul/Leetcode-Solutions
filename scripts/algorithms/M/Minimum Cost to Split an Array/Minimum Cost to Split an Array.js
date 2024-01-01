// Runtime: 138 ms (Top 100.0%) | Memory: 48.10 MB (Top 100.0%)

var minCost = function(nums, k) {
    const n = nums.length, dp = Array(n + 1).fill(Infinity);

    dp[0] = 0;
    for (let i = 0; i < n; i++) {
        const freq = Array(n + 1).fill(0);
        for (let j = i, trimmedLength = 0; j >= 0; j--) {
            trimmedLength += (++freq[nums[j]] > 1) + (freq[nums[j]] == 2);
            dp[i + 1] = Math.min(dp[i + 1], dp[j] + k + trimmedLength);
        }
    }

    return dp[n];
};
