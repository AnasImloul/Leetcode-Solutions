// Runtime: 172 ms (Top 28.33%) | Memory: 54.8 MB (Top 73.33%)
/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToSplitArray = function(nums) {
    let result = 0;
    let letsum = 0;
    let rightsum = nums.reduce((a,b)=> a+b);
    let end = nums.length-1;
    for (let i = 0;i<end;i++) {
        letsum+=nums[i];
        rightsum-=nums[i];
        if (letsum>=rightsum) {
            result++;
        }
    }
    return result;
};