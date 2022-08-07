var combinationSum4 = function(nums, target) {
    const dp = Array(target + 1).fill(0);
    
    nums.sort((a,b) => a - b);
    
    for(let k=1; k <= target; k++) {
        for(let n of nums) {
            if(k < n) break;
            dp[k] += (k == n) ? 1 : dp[k-n];
        }
    }
     
    return dp[target];
};
