// Runtime: 107 ms (Top 53.0%) | Memory: 58.87 MB (Top 40.5%)

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxArrayValue = function(nums) {
    for (let i = nums.length - 1; i >= 0; i--) {
        if (nums[i] >= nums[i-1]) {
            nums[i-1] = nums[i] + nums[i-1];
        }
    }

    return nums[0];
};