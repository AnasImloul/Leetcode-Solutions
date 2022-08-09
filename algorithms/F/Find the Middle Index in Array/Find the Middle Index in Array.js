var findMiddleIndex = function(nums) {
    for (let i = 0; i < nums.length; i++) {
        let leftNums = nums.slice(0, i).reduce((a, b) => a + b, 0);
        let rightNums = nums.slice(i + 1).reduce((a, b) => a + b, 0);
        if (leftNums === rightNums) {
            return i;
        }
    }
    return -1;
};
