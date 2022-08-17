var findMaxConsecutiveOnes = function(nums) {
    let count =0
    let max =0
    for(let i=0; i<nums.length; i ++){
        if(nums[i]==1){
            count ++
        }
        if(nums[i]==0 || i==nums.length-1){
            max = Math.max(count,max)
            count = 0
        }
    }
    return max
};
