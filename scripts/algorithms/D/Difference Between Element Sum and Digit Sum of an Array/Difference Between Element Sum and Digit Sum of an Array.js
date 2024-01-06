// Runtime: 63 ms (Top 61.71%) | Memory: 45.00 MB (Top 60.14%)

/**
 * @param {number[]} nums
 * @return {number}
 */
var differenceOfSum = function(nums) {
    const elementsSum = nums.reduce((acc, val) => acc += val, 0);
    const digitsSum = nums.join('').split('').reduce((acc, val) => acc += +val, 0);

    return elementsSum - digitsSum;
};
