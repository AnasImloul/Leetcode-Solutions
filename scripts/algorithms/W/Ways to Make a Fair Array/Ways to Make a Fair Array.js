/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToMakeFair = function(nums) {
    let oddSum = 0; 
    let evenSum = 0 ;
    let count = 0;
    
    for (let i = 0; i < nums.length; i++) {
        if (i % 2 === 0) {
            evenSum += nums[i];
        } else {
            oddSum += nums[i];
        }
    }
    
    
    for (let i = 0; i < nums.length; i++) {
        if (i % 2 === 0) {
            evenSum -= nums[i];
            if (evenSum === oddSum) {
                count++; 
            }
            oddSum += nums[i];
        } else {
            oddSum -= nums[i];
            if (evenSum === oddSum) {
                count++;
            }
            evenSum += nums[i]
        }
    }
    
    return count;
};


