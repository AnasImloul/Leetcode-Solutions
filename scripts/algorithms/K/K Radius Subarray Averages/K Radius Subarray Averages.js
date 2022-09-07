// Runtime: 629 ms (Top 35.29%) | Memory: 80.4 MB (Top 80.39%)
var getAverages = function(nums, k) {
    const twoK = 2 * k;
    const windowSize = twoK + 1;

    const result = [...nums].fill(-1);
    let sum = 0;
    for (let i = 0; i < nums.length; i++) {
        sum += nums[i];
        if (i >= twoK) {
            result[i - k] = Math.floor(sum / windowSize)
            sum -= nums[i - twoK];
        }
    }
    return result;
};