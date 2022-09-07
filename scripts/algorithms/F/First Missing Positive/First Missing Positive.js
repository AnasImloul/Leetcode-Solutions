// Runtime: 89 ms (Top 95.64%) | Memory: 46.2 MB (Top 94.14%)
/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function (nums) {

    //first make all negative numbers to zero =>zero means we ignore whis number
    for (let index = 0; index < nums.length; index++) {
        if (nums[index] < 0)
            nums[index] = 0
    }

    for (let index = 0; index < nums.length; index++) {
        const temp = Math.abs(nums[index])
        const element = temp - 1

        if (element < nums.length && element >= 0)
            nums[element] = nums[element] === 0 ? -(nums.length + 1) : Math.abs(nums[element]) * -1

    }

    for (let index = 0; index < nums.length; index++) {
        const element = (nums[index])
        if (element >= 0) return index + 1

    }
    return nums.length+1

};