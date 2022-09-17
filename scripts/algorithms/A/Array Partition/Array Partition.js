// Runtime: 211 ms (Top 22.61%) | Memory: 47.1 MB (Top 91.83%)
var arrayPairSum = function(nums) {
    nums.sort((a, b) => a - b);
    let total = 0;
    for (let i = 0; i < nums.length; i += 2) {
        total += Math.min(nums[i], nums[i + 1]);
    }
    return total;
};