/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} t
 * @return {boolean}
 */
var containsNearbyAlmostDuplicate = function(nums, k, t) {
    if(nums.length <2) return false;
    
    let isValid = false;
    
    for(var indexI=0; indexI<nums.length; indexI++){
       let indexJ =  indexI+1;
       while((indexJ - indexI) <= k){
           if(Math.abs(nums[indexI] - nums[indexJ]) <= t){
              isValid= true;
              break;
           }
           indexJ++;
       }
      if (isValid) break;
    }
    
    return isValid;
};
