// Runtime: 69 ms (Top 72.22%) | Memory: 58.80 MB (Top 11.11%)

/**
 * @param {number[]} nums
 * @return {number}
 */
var minimizeArrayValue = function(nums) {
    let res = nums[0], total = nums[0]
    for(let i=1;i<nums.length;i++){
        total += nums[i]
        res = Math.max(res, Math.ceil(total/(i+1)))
    }
    return res
};
