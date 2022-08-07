var findLHS = function(nums) {
    let countNumber = {};
    let result = [];
    for (let i=0; i<nums.length; i++) {
        if (!countNumber[nums[i]]) {
            countNumber[nums[i]] = 1;
        } else {
            countNumber[nums[i]]++;
        }
    }
    for (let value of Object.keys(countNumber)) {
        let count;
        let current = parseInt(value);
        if (countNumber[current + 1]) {
            count = countNumber[current] + countNumber[current + 1];    
            result.push(count);
        }
    };
    if (result.length === 0) {
        return 0;
    }
    return Math.max(...result);
};
