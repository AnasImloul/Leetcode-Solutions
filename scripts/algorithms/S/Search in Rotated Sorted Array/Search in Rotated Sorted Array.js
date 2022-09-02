// Runtime: 79 ms (Top 69.19%) | Memory: 42.6 MB (Top 17.29%)
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    const len = nums.length;
    if (len === 1 && nums[0] === target) return 0;
    const h = nums.findIndex((val, i) => nums[i === 0 ? nums.length - 1 : i - 1] > val);
    if (h !== 0) nums = nums.slice(h).concat(nums.slice(0, h));
    // console.log(h, nums)
    let lo = 0, hi = len - 1;
    while (lo !== hi) {
        if (lo + 1 === hi) {
            if (nums[lo] === target) return (lo + h) % len;
            if (nums[hi] === target) return (hi + h) % len;
            break;
        }

        const i = Math.floor((lo + hi + 1) / 2);
        // console.log(lo, hi, i)
        const val = nums[i];
        if (val === target) return (i + h) % len;
        if (val > target) hi = i;
        else lo = i;
    }

    return -1;
};