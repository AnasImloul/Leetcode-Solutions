var findFinalValue = function(nums, original) {
    while (nums.includes(original)) {
        original = original * 2
    }
    
    return original
};
