var maximumTop = function(nums, k) {
    const MIN = Number.MIN_SAFE_INTEGER;
    const n = nums.length;
    
    if (k === 0) return nums[0];
    if (n === 1 && k % 2 == 1) return -1; // if there is only 1 item and k is odd, then the last move always will be removing the item
    if (k === 1) return nums[1];
    if (k > n) return Math.max(...nums);
    
    let max = MIN;
    
    for (let i = 1; i <= k - 1; ++i) {
        const num = nums[i - 1];
        max = Math.max(max, num);
    }
   
    if (k < n) return Math.max(max, nums[k]); // If there is 1 or more item than k in the array, then the two choices we have is to remove
                                              // k elements which will make the nums[k] be the topmost element or removing k - 1 elements
                                              // and putting the largest number from there back onto the pile.
    
    return max;
};
