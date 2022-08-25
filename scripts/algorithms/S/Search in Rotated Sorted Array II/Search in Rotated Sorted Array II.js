// Runtime: 61 ms (Top 98.58%) | Memory: 42.3 MB (Top 80.97%)
var search = function(nums, target) {
    let found = nums.findIndex(c=> c==target);
    if(found === -1) return false
    else
        return true
};