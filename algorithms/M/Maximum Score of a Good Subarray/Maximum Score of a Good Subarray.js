/*

	JAVASCRIPT

 */
var maximumScore = function(nums, k) {
    // iterate to the left to update the minimum value at each index
    let min = nums[k];
    for (let i = k - 1; i >= 0; i--) {
        min = Math.min(min, nums[i]);
        nums[i] = min;
    }

    // iterate to the right to update the minimum value at each index
    min = nums[k];
    for (let i = k + 1; i < nums.length; i++) {
        min = Math.min(min, nums[i]);
        nums[i] = min;
    }
    
    // start with 2 pointers at opposite ends of nums
    let left = 0;
    let right = nums.length - 1;
    let bestScore = 0;

    while (left <= right) {
        bestScore = Math.max(bestScore, Math.min(nums[left], nums[right]) * (right - left + 1));
        
        // first to check if either pointer is at k
        // if it is at k then we must move the other pointer inwards
        if (left === k) {
            right--;
        } else if (right === k) {
            left++
            
        // if neither index is at k move the pointer
        // that is smaller inwards
        } else if (nums[left] < nums[right]) {
            left++;
        } else {
            right--;
        }
    }
    return bestScore;
};
