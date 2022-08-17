var rangeSum = function(nums, n, left, right) {
    const sums = [];
    
    for (let i = 0; i < nums.length; i++) {
        let sum = 0;
        
        for (let j = i; j < nums.length; j++) {
            sum += nums[j];
            sums.push(sum);
        }
    }
    
    sums.sort((a, b) => a - b);
    
    let ans = 0;
    
    for (let i = left - 1; i < right; i++) {
        ans += sums[i];
    }
    
    return ans % 1000000007;
};
