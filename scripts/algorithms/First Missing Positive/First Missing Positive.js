//O(n) time O(1) space
var firstMissingPositive = function(nums) {
    let n = nums.length;
    for(let i = 0; i < n; i++) {  // This loop helps us to handle the negative numbers
        if(nums[i] <= 0) nums[i] = n + 1;
    }
    for(let i = 0; i < n; i++) {
        let id = Math.abs(nums[i]) - 1;
        nums[id] = Math.abs(nums[id]) * - 1;
    }
    for(let i = 0; i < n; i++) {
        if(nums[i] > 0) return i + 1;
    }
    return n + 1;
}
