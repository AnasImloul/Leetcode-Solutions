// Runtime: 192 ms (Top 48.39%) | Memory: 61.2 MB (Top 67.74%)
var totalSteps = function(nums) {
    let stack = [],
        dp = new Array(nums.length).fill(0),
        max = 0

    for (let i = nums.length - 1; i >= 0; i--) {
        while (stack.length > 0 && nums[i] > nums[stack[stack.length - 1]]) {
            dp[i] = Math.max(++dp[i], dp[stack.pop()])
            max = Math.max(dp[i], max)
        }
        stack.push(i)
    }
    return max
};