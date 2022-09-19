// Runtime: 713 ms (Top 56.41%) | Memory: 88 MB (Top 92.31%)
var tupleSameProduct = function(nums) {
    let tupleCount = 0;
    let products = {}; // we'll keep track of how many times we've seen a given product before
    for (let a = 0; a < nums.length; a++) {
        for (let b = a + 1; b < nums.length; b++) {
            let product = nums[a] * nums[b];
            if (products[product]) { // we've seen at least one other pair of numbers with the same product already
                tupleCount += 8 * products[product]; // multiply by 8 because for any 4 numbers there are 8 permutations
                products[product] += 1; // increment the count, if we see this product again there are even more possible tuple combinations
            } else {
                products[product] = 1; // mark as seen once
            }
        }
    }
    return tupleCount;
};