var findLengthOfLCIS = function(nums) {
    let res = 0;
    let curr = 1;
    
    nums.forEach((num, idx) => {
        if (num < nums[idx + 1]) {
            curr++;
        }
        else curr = 1;
        
        res = Math.max(res, curr);
    })
    
    return res;
};
