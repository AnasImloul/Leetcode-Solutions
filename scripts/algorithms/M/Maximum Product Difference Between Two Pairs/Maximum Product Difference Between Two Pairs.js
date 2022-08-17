var maxProductDifference = function(nums) {
    nums.sort((a,b) => a-b);
    return nums.slice(nums.length - 2).reduce((a,b) => a*b, 1) - nums.slice(0, 2).reduce((a,b) => a*b, 1);
};
