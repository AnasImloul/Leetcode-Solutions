// Runtime: 131 ms (Top 48.09%) | Memory: 46.3 MB (Top 65.46%)

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