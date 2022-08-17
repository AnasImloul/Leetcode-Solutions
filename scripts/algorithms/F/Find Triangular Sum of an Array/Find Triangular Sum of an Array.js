var triangularSum = function(nums) {
    while(nums.length > 1){
        let arr = []
        for(let i=0; i<nums.length-1; i++){
            arr.push((nums[i] + nums[i+1]) % 10)
        }
        nums = arr
    }
    return nums[0]
};
