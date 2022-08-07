var maxRotateFunction = function(nums) { 
    let n = nums.length;
    let dp = 0;
    
    let sum = 0; 
    for (let i=0; i<n;i++) {
        sum += nums[i];
        dp += i*nums[i];
    }
    let max = dp;
    for (let i=1; i<n;i++) {
        dp += sum - nums[n-i]*n;
        max = Math.max(max, dp);
    } 
    return max;
};