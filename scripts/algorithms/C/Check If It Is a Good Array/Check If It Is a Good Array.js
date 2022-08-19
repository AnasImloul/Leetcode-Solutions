// Runtime: 150 ms (Top 20.00%) | Memory: 48.4 MB (Top 40.00%)

var isGoodArray = function(nums) {
    let gcd = nums[0]

    for(let n of nums){while(n){[gcd, n] = [n, gcd % n]}}

    return (gcd === 1)
};