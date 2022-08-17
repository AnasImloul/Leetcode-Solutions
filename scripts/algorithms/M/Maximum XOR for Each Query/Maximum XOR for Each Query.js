/**
 * @param {number[]} nums
 * @param {number} maximumBit
 * @return {number[]}
 */
var getMaximumXor = function(nums, maximumBit) {
    let xor = (1 << maximumBit) - 1
    for(let i=0; i<nums.length; i++){
        xor ^= nums[i]
        nums[i] = xor
    }
    return nums.reverse()
};
