var shuffle = function(nums, n) {
    while (n--) {
        nums.splice(n + 1, 0, nums.pop());
    }
    return nums;
};
