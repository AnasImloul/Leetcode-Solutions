var NumArray = function(nums) {
    this.nums = nums;
};

NumArray.prototype.sumRange = function(left, right) {
    let sum = 0;
    for(let i = left; i <= right; i++) sum += this.nums[i]
    return sum
};
