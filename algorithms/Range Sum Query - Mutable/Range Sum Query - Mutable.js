var NumArray = function(nums) {
    this.nums = nums;
    this.n = nums.length;
    this.fenwickTree = new Array(this.n + 1).fill(0);
    nums.forEach((num, index) => this.init(index, num));
};

NumArray.prototype.init = function(index, val) {
    let j = index + 1;
    while(j <= this.n) {
        this.fenwickTree[j] += val;
        j += this.lsb(j);
    }
};

NumArray.prototype.lsb = function(index) {
    return index & ~(index - 1);
};

NumArray.prototype.update = function(index, val) {
    const diff = val - this.nums[index];
    this.nums[index] = val;
    this.init(index, diff);
};

NumArray.prototype.getSum = function(index) {
    let j = index + 1;
    let sum = 0;

    while(j > 0) {
        sum += this.fenwickTree[j];
        j -= this.lsb(j);
    }

    return sum;
};

NumArray.prototype.sumRange = function(left, right) {
    return this.getSum(right) - this.getSum(left - 1);
};
