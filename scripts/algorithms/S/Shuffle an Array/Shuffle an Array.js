// Runtime: 308 ms (Top 14.36%) | Memory: 51.8 MB (Top 95.39%)

var Solution = function(nums) {
    this.nums = nums;
    this.resetArray = [...nums];
};

Solution.prototype.reset = function() {
    return this.resetArray;
};

Solution.prototype.shuffle = function() {

    const n = this.nums.length;
    const numsArray = this.nums;

    for (let i = 0; i < n; i++) {
        const j = Math.floor(Math.random() * (n - i)) + i;
        const tmp = numsArray[i];
        numsArray[i] = numsArray[j];
        numsArray[j] = tmp;
    }

    return numsArray;
};