// Runtime: 77 ms (Top 25.0%) | Memory: 48.14 MB (Top 32.1%)

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxAbsoluteSum = function(nums) {
    maxi = Number.MIN_VALUE , mini = Number.MAX_VALUE
    cur_max = 0, cur_min = 0
    for(let i=0; i<nums.length; i++){
        cur_max = Math.max(cur_max+nums[i],nums[i])
        cur_min = Math.min(cur_min+nums[i], nums[i])
        maxi = Math.max(maxi,cur_max)
        mini = Math.min(mini,cur_min)
    }
    return Math.max(maxi,-mini)
};