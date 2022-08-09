var isGoodArray = function(nums) {
    let gcd = nums[0]
    
    for(let n of nums){while(n){[gcd, n] = [n, gcd % n]}}
    
    return (gcd === 1)
};
