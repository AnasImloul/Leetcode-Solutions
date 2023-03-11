var missingNumber = function(nums) {
    return ((1 + nums.length)*nums.length/2) - nums.reduce((a,b) => a+b)
};