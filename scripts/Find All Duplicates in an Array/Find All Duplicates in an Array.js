// Approach : Mark Visited Elements in the Input Array itself
var findDuplicates = function(nums) {
    let result = [];
    for(let i = 0; i < nums.length; i++) {
        let id = Math.abs(nums[i]) - 1;
        if(nums[id] < 0) result.push(id + 1);
        else nums[id] = - Math.abs(nums[id]);
    }
    return result;
};

