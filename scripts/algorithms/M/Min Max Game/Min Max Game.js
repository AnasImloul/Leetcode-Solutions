// Runtime: 105 ms (Top 27.62%) | Memory: 42 MB (Top 97.79%)
var minMaxGame = function(nums) {
    while (nums.length > 1) {
        let half = nums.length / 2;
        for (let i = 0; i < half; i++)
            nums[i] = i % 2 === 0 ? Math.min(nums[2 * i], nums[2 * i + 1]) : Math.max(nums[2 * i], nums[2 * i + 1]);

        nums.length = half;
    }

    return nums[0];
};