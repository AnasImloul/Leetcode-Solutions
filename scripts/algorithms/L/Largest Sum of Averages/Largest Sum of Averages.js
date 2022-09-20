// Runtime: 124 ms (Top 33.33%) | Memory: 44.8 MB (Top 33.33%)
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var largestSumOfAverages = function(nums, k) {
    // set length
    const len = nums.length;
    // set sum by len fill
    const sum = new Array(len).fill(0);
    // set nums first to first of sum
    sum[0] = nums[0];

    // set every item of sum to the sum of the previous and the corresponding item of nums
    for (let i = 1; i < len; i++) {
        sum[i] = sum[i - 1] + nums[i];
    }

    // set dynamic programming
    const dp = new Array(k + 1).fill("").map(() => new Array(len).fill(0));

    // according to the meaning of the problem, set the value of dp
    for (let i = 0; i < len; i++) {
        dp[1][i] = sum[i] / (i + 1);
    }
    for (let i = 1; i <= k; i++) {
        dp[i][i - 1] = sum[i - 1];
    }
    for (let i = 2; i <= k; i++) {
        for (let j = i; j < len; j++) {
            for (let m = j - 1; m >= i - 2; m--) {
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][m] + (sum[j] - sum[m]) / (j - m));
            }
        }
    }

    // result
    return dp[k][len - 1];
};