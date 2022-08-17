var maximumDifference = function(nums) {
    var diff=-1
    for(let i=0;i<nums.length;i++){
        for(let j=i+1;j<nums.length;j++){
            if (nums[j]> nums[i]) diff=Math.max(nums[j]-nums[i],diff)
        }
    }
    return diff
};
