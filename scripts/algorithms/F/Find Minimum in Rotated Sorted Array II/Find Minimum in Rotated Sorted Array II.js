// Runtime: 66 ms (Top 92.37%) | Memory: 42.5 MB (Top 45.04%)
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let min = Infinity;
    let l = 0;
    let r = nums.length - 1;
    while (l <= r) {
        const m = Math.floor((l + r) / 2);

        // Eliminate dupes ......................... only difference from #153
        while (l < m && nums[l] === nums[m]) l++;
        while (r > m && nums[r] === nums[m]) r--;
        // .........................................

        // locate the sorted side, the opposite side has the break point
        // min should be on the side that has the break point, so continue search on that side
        if (nums[l] <= nums[m]) {
            // left side is sorted (or l & m are the same index)
            // brake is on right side
            min = Math.min(min, nums[l]);
            l = m + 1;
        } else {
            // right side is sorted
            // break is on left side
            min = Math.min(min, nums[m]);
            r = m - 1;
        }
    }
    return min;
};