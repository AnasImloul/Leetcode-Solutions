
var canJump = function(nums) {
    let target = nums.length-1;
    let max = 0,index = 0;
    
    while(index <= target){
        max = Math.max(max,index + nums[index]);
        
        if(max >= target) return true;
        
        if(index >= max && nums[index] === 0) return false;
        
        index++;
    }
    
    return false;
};