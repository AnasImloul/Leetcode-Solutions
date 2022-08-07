/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
    const duplicateCheck = {};
    let isValid = false;
    for(var indexI=0; indexI<nums.length;indexI++){
         if(duplicateCheck[nums[indexI]] > -1)  {
            if(Math.abs(duplicateCheck[nums[indexI]] - indexI) <= k) {
              isValid = true;
              break;
            }
            
        }
        duplicateCheck[nums[indexI]] = indexI;
    }
    return isValid;
};
