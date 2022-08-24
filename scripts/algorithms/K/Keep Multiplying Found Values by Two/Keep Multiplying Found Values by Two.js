// Runtime: 76 ms (Top 82.37%) | Memory: 42.4 MB (Top 79.69%)
var findFinalValue = function(nums, original) {
    while (nums.includes(original)) {
        original = original * 2
    }

    return original
};