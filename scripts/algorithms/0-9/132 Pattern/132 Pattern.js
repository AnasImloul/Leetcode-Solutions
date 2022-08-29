// Runtime: 85 ms (Top 89.19%) | Memory: 53.4 MB (Top 61.26%)
var find132pattern = function(nums) {
    let m = -Infinity
    // Initialise a empty stack...
    const stack = []
    // Run a Loop from last to first index...
    for (let i = nums.length - 1; i >= 0; i--) {
        // If nums[i] is greater than the top element of stack, then pop the element...
        while (nums[i] > stack[stack.length - 1]) {
            m = stack.pop()
        }
        // If m is greater than nums[i], return true...
        if (nums[i] < m) {
            return true
        }
        // Otherwise, push nums[i] into stack...
        stack.push(nums[i])
    }
    // If the condition is not satisfied, return false.
    return false
};