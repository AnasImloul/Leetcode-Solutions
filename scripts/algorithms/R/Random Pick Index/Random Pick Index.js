// Runtime: 412 ms (Top 30.40%) | Memory: 89.1 MB (Top 48.00%)
var Solution = function(nums) {
    this.map = nums.reduce((result, num, index) => {
        const value = result.get(num) ?? [];

        value.push(index);
        result.set(num, value);
        return result;
    }, new Map());
};

Solution.prototype.pick = function(target) {
    const pick = this.map.get(target);
    const random = Math.random() * pick.length | 0;

    return pick[random];
};