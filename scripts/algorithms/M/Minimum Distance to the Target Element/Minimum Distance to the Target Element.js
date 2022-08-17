var getMinDistance = function(nums, target, start) {
    let min = Infinity;
    for(let i=nums.indexOf(target);i<nums.length;i++){
        if(nums[i]===target){
            if(Math.abs(i-start)<min) min = Math.abs(i-start);
        }
    }
    return min;
};
