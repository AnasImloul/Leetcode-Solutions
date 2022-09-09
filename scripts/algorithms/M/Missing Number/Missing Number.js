// Runtime: 90 ms (Top 77.79%) | Memory: 44.2 MB (Top 70.06%)
var missingNumber = function(nums) {
    // Initialize res as zero...
    let res = 0;
    // Traverse all the element through the loop...
    for (let i = 0; i < nums.length; ++i) {
        // Calculation process by helping of Bit Manipulation...
        res ^= nums[i] ^ (i + 1);
    }
    return res; // Return the result
};