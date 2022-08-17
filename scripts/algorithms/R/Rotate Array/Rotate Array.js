/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    const len = nums.length;
    k %= len;
    const t = nums.splice(len - k, k);
    nums.unshift(...t);
};
