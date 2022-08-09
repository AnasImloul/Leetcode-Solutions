var maxProduct = function(nums) {
    let val = [];
    for(let i=0; i<nums.length; i++){
        for(let j=i+1; j<nums.length; j++){
            val.push((nums[i]-1)*(nums[j]-1))
        }
    }
    return Math.max(...val)
};
