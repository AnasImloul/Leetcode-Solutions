// Runtime: 134 ms (Top 41.38%) | Memory: 50.9 MB (Top 15.52%)
var maxSumDivThree = function(nums) {
    // there are 3 options for how the sum fit's into 3 via mod % 3
    // track those 3 options via indices in the dp array
    // dp[0] = %3 === 0
    // dp[1] = %3 === 1
    // dp[2] = %3 === 2
    let dp = new Array(3).fill(0);
    for (let num of nums) {
        for (let i of dp.slice(0)) {
            let sum = i + num;
            let mod = sum % 3;
            // on each pass, set the value of dp[mod] to the Math.max val
            dp[mod] = Math.max(dp[mod], sum);
        }
    }
    return dp[0];
};