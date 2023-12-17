// Runtime: 326 ms (Top 11.11%) | Memory: 107.70 MB (Top 66.67%)

/**
 * @param {number[]} nums
 * @return {number}
 */
var numberOfArithmeticSlices = function(nums) {
    let cache = new Map();
    let result = 0;
    for(let i=0;i<nums.length;i++){
        cache[i] = new Map();
        for(let j=0;j<i;j++){
            let diff = nums[i]-nums[j];
            let cacheOne = cache[i].get(diff) || 0;
            let cacheTwo = cache[j].get(diff) || 0;
            result += cacheTwo;
            cache[i].set(diff,cacheOne + cacheTwo+1);
        }
    }
    return result;
};
