// Runtime: 107 ms (Top 42.98%) | Memory: 44.3 MB (Top 39.57%)

/**
 * @param {number[]} nums
 * @return {number}
 */
var smallestEqual = function(nums) {
    return nums.findIndex((n, i) => i % 10 === n)
};