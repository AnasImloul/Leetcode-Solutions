/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function(nums) {
   //step 1
    var tot=0;
    for (let i = 0; i < nums.length; i++) {
        tot+= nums[i];       
    }
    // Step 2
    left = 0 ;
    for (let j = 0; j < nums.length; j++) {
        right = tot - nums[j] - left;
        if (left == right){
            return j
        }
        left += nums[j];
    }
    return -1
};