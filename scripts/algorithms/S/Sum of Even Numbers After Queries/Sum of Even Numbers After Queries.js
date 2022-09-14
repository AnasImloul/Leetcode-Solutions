// Runtime: 187 ms (Top 62.12%) | Memory: 50.6 MB (Top 51.52%)
/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number[]}
 */
var sumEvenAfterQueries = function(nums, queries) {
    let sumEven = 0, ans = []
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] % 2 == 0) sumEven += nums[i]
    }

    for (let [val, idx] of queries) {
        if (nums[idx] % 2 == 0) {
            if (val % 2 == 0) sumEven += val
            else sumEven -= nums[idx]
        } else {
            // odd + odd
            if (val % 2 !== 0) sumEven += nums[idx] + val
        }
        nums[idx] += val
        ans.push(sumEven)
    }

    return ans
};