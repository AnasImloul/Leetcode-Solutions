/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    const L = new Array(nums.length).fill(1)
    
    for (let i = 1; i < nums.length; i++) {
        for (let j = 0; j < i; j++) {
            if (nums[j] < nums[i] && L[j] + 1 > L[i]) {
                L[i] = L[j] + 1
            }
        }
    }
    return Math.max(...L);
};
