var findDisappearedNumbers = function(nums) {
    let result = [];
    for(let i = 0; i < nums.length; i++) {
        let id = Math.abs(nums[i]) - 1;
        nums[id] = - Math.abs(nums[id]);
    }
    for(let i = 0; i < nums.length; i++) {
        if(nums[i] > 0) result.push(i + 1);
    }
    return result;
};
