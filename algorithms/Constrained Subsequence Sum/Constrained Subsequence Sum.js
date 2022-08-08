/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var constrainedSubsetSum = function(nums, k) {
    const queue = [[0, nums[0]]];
    let max = nums[0];
    for (let i = 1; i < nums.length; i++) {
        const cur = queue.length ? nums[i] + Math.max(0, queue[0][1]) : nums[i];
        max = Math.max(max, cur);
        while(queue.length && queue[queue.length-1][1] < cur) queue.pop();
        queue.push([i, cur]);
        while(queue.length && queue[0][0] <= i-k) queue.shift();
    }
    return max;
};
