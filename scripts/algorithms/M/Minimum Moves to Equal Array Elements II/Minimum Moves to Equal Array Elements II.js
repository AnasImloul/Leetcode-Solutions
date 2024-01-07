// Runtime: 55 ms (Top 86.29%) | Memory: 43.80 MB (Top 90.32%)

var minMoves2 = function(nums) {
    // Sort the array low to high
    nums.sort(function(a, b) { return a-b;});
    let i = 0;
    let j = nums.length - 1;
    let res = 0;
    /**
     * Sum up the difference between the next highest and lowest numbers. Regardless of what number we wish to move towards, the number of moves is the same.
     */
    while (i < j){
        res += nums[j] - nums[i];
        i++;
        j--;
    }
    return res;
};
