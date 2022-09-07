// Runtime: 99 ms (Top 29.63%) | Memory: 41.6 MB (Top 91.36%)
var maxAscendingSum = function(nums) {
    const subarray = nums.reduce((acc, curr, index) => {
        curr > nums[index - 1] ? acc[acc.length - 1] += curr : acc.push(curr);
        return acc;
    }, []);

    return Math.max(...subarray);
};