// Runtime: 74 ms (Top 100.0%) | Memory: 59.20 MB (Top 53.85%)

// Main Function
var numOfWays = function(nums) {
    return (helper(nums) - 1n) % BigInt(1e9+7) // Return modulo value
};

// Function return combination (Mathematics) [Formula = n!/( k!*(n-k)!)]
var nCr = (n,r) => {
    if(n < 2) return 1n;
    n = BigInt(n), r = BigInt(r);
    return fact(n) / (fact(n-r) * fact(r));
}

const cache = new Map(); // Chache for factorials
// Returns factorial of n [Formula = n!]
var fact = (n) => {
    if(n < 2) return 1n;
    if(cache.has(n)) return cache.get(n);
    const res = BigInt(n) * fact(n - 1n);
    cache.set(n, res);
    return res;
}

var helper = (nums) => {
    if(nums.length < 3) return 1n;

    const left = [], right = []
    // Separate lower and higher values than first element in nums
    for(let i=1; i<nums.length; ++i) {
        if(nums[i] < nums[0]) left.push(nums[i])
        if(nums[i] > nums[0]) right.push(nums[i])
    }

    // Number of possible combinations to get left and right separated
    const comb = nCr(nums.length-1, left.length)
    return comb * helper(left) * helper(right);
}
