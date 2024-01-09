// Runtime: 138 ms (Top 64.29%) | Memory: 54.70 MB (Top 39.29%)

var findValueOfPartition = function(nums) {
    nums.sort((a,b) => a-b)
    let res = Infinity
    
    for (let i=0; i<nums.length-1; i++) {
        const diff = Math.abs(nums[i] - nums[i+1])
        if (diff < res) {
            res = diff
        }
    }
    
    return res
};
