/**
 * @param {number[]} nums
 * @param {number[]} index
 * @return {number[]}
 */
var createTargetArray = function(nums, index) {
   Array.prototype.insert = function ( index, item ) {
    this.splice( index, 0, item );
    };
    let result=[]
    for(let i=0;i<nums.length;i++){
        result.insert(index[i],nums[i]);
    }
    return result;
};
