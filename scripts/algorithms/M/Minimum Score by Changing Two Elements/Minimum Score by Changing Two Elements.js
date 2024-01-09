// Runtime: 115 ms (Top 100.0%) | Memory: 51.30 MB (Top 75.0%)

/**
 * @param {number[]} nums
 * @return {number}
 */
var minimizeSum = function(nums) {
    nums.sort((a, b) => a - b)
    
    return Math.min(
        nums.at(-3) - nums[0],
        nums.at(-2) - nums[1],
        nums.at(-1) - nums[2]
    )
};
