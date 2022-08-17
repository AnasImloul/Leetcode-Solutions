/**
 * @param {number[]} nums
 * @return {number}
 */
var smallestEqual = function(nums) {
    return nums.findIndex((n, i) => i % 10 === n)
};
