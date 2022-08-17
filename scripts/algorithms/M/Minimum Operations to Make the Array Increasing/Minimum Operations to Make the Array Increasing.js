var minOperations = function(nums) {
    if(nums.length < 2) return 0;
    let count = 0;
    for(let i = 1; i<nums.length; i++) {
       if(nums[i] <= nums[i-1]) {
           let change = nums[i-1] - nums[i] + 1;
           count += change;
           nums[i] += change;
       }
    }
    
    return count;
};
