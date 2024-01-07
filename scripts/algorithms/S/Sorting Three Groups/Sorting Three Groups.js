// Runtime: 129 ms (Top 92.31%) | Memory: 49.20 MB (Top 69.23%)

var minimumOperations = function(nums) {
    const dp = [0, 0, 0];
    for (let i = 0; i < nums.length; i++)
        for (let j = 0, min = dp[0]; j <= 2; j++)
            dp[j] = (min = Math.min(min, dp[j])) + (nums[i] !== j + 1);

    return Math.min(...dp);
};
