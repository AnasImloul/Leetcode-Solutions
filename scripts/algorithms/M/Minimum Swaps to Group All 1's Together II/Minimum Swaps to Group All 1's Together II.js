// Runtime: 102 ms (Top 90.00%) | Memory: 56.1 MB (Top 32.50%)
var minSwaps = function(nums) {
    const MAX = Number.MAX_SAFE_INTEGER;

    let ones = nums.reduce((acc, bit) => acc + bit, 0);

    const doubledNums = nums.concat(nums.slice(0, nums.length - 1));

    let minSwap = MAX;
    let left = 0;
    let onesWithinWindow = 0;

    for (let i = 0; i < doubledNums.length; ++i) {
        const rightBit = doubledNums[i];

        if (rightBit === 1) onesWithinWindow += 1;

        if (i >= ones) {
            const leftBit = doubledNums[left];

            if (leftBit === 1) onesWithinWindow -= 1;
            ++left;
        }

        if (i + 1 >= ones) minSwap = Math.min(minSwap, ones - onesWithinWindow);
    }

    return minSwap;
};