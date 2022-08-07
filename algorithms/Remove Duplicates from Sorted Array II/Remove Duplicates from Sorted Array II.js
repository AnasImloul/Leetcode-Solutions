var removeDuplicates = function(nums) {
    let i = 0;
    let count = 0;
    for(let num of nums) {
        (num == nums[i - 1]) ? count++ : count = 1;
        if(i == 0 || (num >= nums[i - 1] && count <= 2)) nums[i++] = num;
    }
    return i;
};
