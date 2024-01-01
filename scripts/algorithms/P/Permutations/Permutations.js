// Runtime: 80 ms (Top 8.91%) | Memory: 44.70 MB (Top 69.1%)

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    const result = [];
    const backtrack = (nums, path) => {
        if (nums.length === 0) {
            result.push(path);
            return;
        }
        for (let i = 0; i < nums.length; i++) {
            backtrack([...nums.slice(0, i), ...nums.slice(i + 1)], [...path, nums[i]]);
        }
    };
    backtrack(nums, []);
    return result;
};
