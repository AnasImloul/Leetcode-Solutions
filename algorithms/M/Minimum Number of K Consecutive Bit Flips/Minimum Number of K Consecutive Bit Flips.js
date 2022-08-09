var minKBitFlips = function(nums, k) {
    let count = 0
    
    for(let i=0; i<nums.length; i++){
        if (nums[i] == 0){
            for(let j=0; j<k && i+k <= nums.length; j++){
                nums[i+j] = 1 - nums[i+j]
            }
            count++
        }
    }
        
    return nums.every(n => n ==1) ? count : -1
};
