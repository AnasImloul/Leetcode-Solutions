// Runtime: 83 ms (Top 65.37%) | Memory: 43.7 MB (Top 52.05%)

var arraySign = function(nums) {
    // use filter to find total negative numbers in the array
    let negativeCount = nums.filter(n => n<0).length;

    // check if the nums array has zero. If it does, then return 0
    if(nums.includes(0)) return 0;

    // If negativeCount variable is even answer is 1 else -1
    return negativeCount % 2 === 0 ? 1 : -1
};