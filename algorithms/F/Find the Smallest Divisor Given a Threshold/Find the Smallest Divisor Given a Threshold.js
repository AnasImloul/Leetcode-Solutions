var smallestDivisor = function(nums, threshold) {
    let left = 1;
    let right = nums.reduce((r, x) => Math.max(r, x), 0);
    
    while (left <= right) {
        const div = Math.floor((left + right) / 2);
        const sum = nums.reduce((r, x) => r + Math.ceil(x / div), 0);
        
        if (sum <= threshold) {
            right = div - 1;
        } else {
            left = div + 1;
        }
    }
    
    return left;
};
