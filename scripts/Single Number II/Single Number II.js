 /**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    if(nums.length === 1) return nums[0];
    
    const objNums = {};
    for(var indexI=0; indexI<nums.length; indexI++){
       if(objNums[nums[indexI]] === 2) delete objNums[nums[indexI]];
       else objNums[nums[indexI]] = (objNums[nums[indexI]] || 0) + 1;
    }
    
    return Object.keys(objNums)[0];
};
