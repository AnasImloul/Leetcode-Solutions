// Runtime: 111 ms (Top 29.35%) | Memory: 42.3 MB (Top 82.36%)
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
    const n = nums.length - 1;
    let ans = nums[0];
    let l = 1, r = 1;

    for (let i = 0; i < nums.length; i++) {
        l = (l ? l : 1) * nums[i];
        r = (r ? r : 1) * nums[n - i];
        ans = Math.max(ans, Math.max(l, r));
    }

    return ans;
};