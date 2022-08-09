var isMonotonic = function(nums) {
    let increasingCount = 0;
    let decreasingCount = 0;
    for(let i = 1; i < nums.length; i++){
        if(nums[i] > nums[i-1]){
            increasingCount++;
        }else if(nums[i] < nums[i-1]){
            decreasingCount++;
        }
    }
    
    return !(increasingCount && decreasingCount);
};