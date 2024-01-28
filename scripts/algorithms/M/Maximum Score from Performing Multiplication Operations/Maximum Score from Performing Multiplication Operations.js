// Runtime: 93 ms (Top 88.52%) | Memory: 64.00 MB (Top 63.93%)

/**
 * @param {number[]} nums
 * @param {number[]} multipliers
 * @return {number}
 */
var maximumScore = function(nums, multipliers) {
    // using an array as memo will be faster 
    // in processing than using an object
    let memo = new Array(multipliers.length+1).fill(0)
        .map(() => new Array(multipliers.length+1).fill(0)); 
        
    // starting point will be from the end 
    for (let i = multipliers.length - 1; i >= 0; i--) {    
        // at state i, used i elements from nums
        // and left nums.length - i consecutive elements
        // those consecutive elements can be seen as the rest block
        // the left of the rest block can be any where from i to 0
        // whereas the left element that this state can use is from the rest block
        // so left = i to 0;
        for (let left = i; left >= 0; left--) {
            let right = (nums.length - 1) -  (i - left);

            // calculate all possible cases for state i
            // each case will combine with each case of state i - 1 and so on            
            memo[i][left] = Math.max(
                multipliers[i] * nums[left] + memo[i+1][left+1],
                multipliers[i] * nums[right] + memo[i+1][left]
            );
        }
    }

    // finish the calculation and 
    // return the last case that we calculated
    return memo[0][0];
}
