// Runtime: 156 ms (Top 53.33%) | Memory: 45.2 MB (Top 100.00%)
var minOperations = function(nums) {
    let maxpow = 0, ans = 0, pow, val
    for (let i = 0; i < nums.length; i++) {
        for (val = nums[i], pow = 0; val > 0; ans++)
            if (val % 2) val--
            else pow++, val /= 2
        ans -= pow
        if (pow > maxpow) maxpow = pow
    }
    return ans + maxpow
};