var checkPossibility = function(nums) {
    let changed = false
    for(let i=nums.length-1; i>0; i--) {
        if(nums[i-1] > nums[i]) {
            if(changed) return false;
            if(i === nums.length-1 || nums[i-1] < nums[i+1]) nums[i] = nums[i-1]
            else nums[i-1] = nums[i];
            changed = true
        }
    }
    return true;
};
