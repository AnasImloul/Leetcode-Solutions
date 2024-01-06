// Runtime: 90 ms (Top 92.05%) | Memory: 47.40 MB (Top 50.0%)

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximizeSum = function(nums, k) {
    let max = Math.max(...nums);
    sum = max;
    for(let i=1; i<k; i++){
        sum+= max+i;
    }
    return sum;
};
