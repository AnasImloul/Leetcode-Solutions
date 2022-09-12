// Runtime: 155 ms (Top 80.49%) | Memory: 60.8 MB (Top 63.42%)
/**
 * @param {number[]} nums
 * @return {number}
 */
var sumOfBeauties = function(nums) {
    let min = nums[0], max = Infinity, maxArr = [], total = 0;

    // Creating an array, which will keep the record of minimum values from last index
    for(let i=nums.length-1; i>1; i--) {
        if(nums[i] < max) max = nums[i];
        maxArr.push(max);
    }

    // iterating through array to check the given conditions
    for(let i=1; i<nums.length-1; i++) {

        // Keeping a record of max value from all index < i
        if(nums[i-1] > min) min = nums[i-1];

        // Checking conditions
        if(nums[i] < maxArr.pop() && min < nums[i]) total += 2;
        else if(nums[i-1] < nums[i] && nums[i] < nums[i+1]) total += 1;
    }

    return total;
};