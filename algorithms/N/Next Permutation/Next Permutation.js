/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function(nums) {
    const dsc = nums.slice();
    dsc.sort((a, b) => b - a);
    if (dsc.every((n, i) => n === nums[i])) {
        nums.sort((a, b) => a - b);
    } else {
        const len = nums.length;
        let lo = len - 1, hi;
        while (nums[lo] === dsc[dsc.length - 1]) {
            lo--;
            dsc.pop();
        }
        while (lo >= 0) {
            // console.log(lo, nums[lo], nums.slice(lo + 1))
            hi = nums.slice(lo + 1).reverse().findIndex((n) => n > nums[lo]);
            if (hi !== -1) {
                hi = len - 1 - hi;
                break;
            }
            lo--;
        }

        const lval = nums[lo];
        // console.log(lo, lval, hi, nums[hi]);
        nums[lo] = nums[hi];
        nums[hi] = lval;
        const sorted = nums.slice(lo + 1);
        // console.log(nums, sorted)
        sorted.sort((a, b) => a - b);
        for (let i = 0; i < sorted.length; i++)
            nums[lo + 1 + i] = sorted[i];
    }
};
