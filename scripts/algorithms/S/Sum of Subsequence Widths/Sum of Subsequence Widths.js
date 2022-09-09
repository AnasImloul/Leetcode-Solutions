// Runtime: 450 ms (Top 11.11%) | Memory: 53.8 MB (Top 66.67%)
var sumSubseqWidths = function(nums) {
    const mod = 1000000007;
    nums.sort((a, b) => a - b), total = 0, power = 1;
    for(let i = 0; i < nums.length; i++) {
        total = (total + nums[i] * power) % mod;
        power = (power * 2) % mod;
    }

    power = 1;
    for(let i = nums.length - 1; i >= 0; i--) {
        total = (total - nums[i] * power + mod) % mod;
        power = (power * 2) % mod;
    }

    return (total + mod) % mod
};