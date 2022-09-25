// Runtime: 153 ms (Top 49.62%) | Memory: 44.3 MB (Top 25.19%)
var findNumberOfLIS = function(nums) {
    const { length } = nums;
    const dpLength = Array(length).fill(1);
    const dpCount = Array(length).fill(1);

    for (let right = 0; right < length; right++) {
        for (let left = 0; left < right; left++) {
            if (nums[left] >= nums[right]) continue;
            if (dpLength[left] + 1 === dpLength[right]) {
                dpCount[right] += dpCount[left];
            } else if (dpLength[left] + 1 > dpLength[right]) {
                dpLength[right] = dpLength[left] + 1;
                dpCount[right] = dpCount[left];
            }
        }
    }

    const maxLength = Math.max(...dpLength);
    return dpLength.reduce((result, length, index) => {
        const count = dpCount[index];
        return result + (maxLength === length ? count : 0);
    }, 0);
};