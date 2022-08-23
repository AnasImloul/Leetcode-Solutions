// Runtime: 85 ms (Top 81.32%) | Memory: 43.9 MB (Top 72.24%)
var removeDuplicates = function(nums) {
    let i = 0;
    let count = 0;
    for(let num of nums) {
        (num == nums[i - 1]) ? count++ : count = 1;
        if(i == 0 || (num >= nums[i - 1] && count <= 2)) nums[i++] = num;
    }
    return i;
};