// Runtime: 134 ms (Top 11.99%) | Memory: 44.2 MB (Top 60.87%)
var shuffle = function(nums, n) {
    while (n--) {
        nums.splice(n + 1, 0, nums.pop());
    }
    return nums;
};