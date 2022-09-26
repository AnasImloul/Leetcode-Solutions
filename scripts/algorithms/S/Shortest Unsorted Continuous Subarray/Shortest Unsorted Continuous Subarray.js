// Runtime: 177 ms (Top 10.70%) | Memory: 46.2 MB (Top 31.77%)
var findUnsortedSubarray = function(nums) {
    let left = 0;
    let right = nums.length - 1;
    const target = [...nums].sort((a, b) => a - b);

    while (left < right && nums[left] === target[left]) left += 1;
    while (right > left && nums[right] === target[right]) right -= 1;
    const result = right - left;

    return result === 0 ? 0 : result + 1;
};