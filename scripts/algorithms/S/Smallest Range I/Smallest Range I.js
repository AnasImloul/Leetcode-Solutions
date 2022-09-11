// Runtime: 90 ms (Top 57.43%) | Memory: 43.8 MB (Top 84.16%)
var smallestRangeI = function(nums, k) {
    let max = Math.max(...nums);
    let min = Math.min(...nums);
    return Math.max(0, max - min- 2*k)
};