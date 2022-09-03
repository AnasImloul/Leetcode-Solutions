// Runtime: 108 ms (Top 26.95%) | Memory: 41.6 MB (Top 95.74%)
var minimumOperations = function(nums) {
    let k = new Set(nums) // convert array to set; [...nums] is destructuring syntax
    return k.has(0) ? k.size-1 : k.size; // we dont need 0, hence if zero exists return size-1
};