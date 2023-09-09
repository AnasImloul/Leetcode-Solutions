// Runtime: 4931 ms (Top 33.3%) | Memory: 51.20 MB (Top 40.3%)

/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} t
 * @return {boolean}
 */
var containsNearbyAlmostDuplicate = function(nums, k, t) {
   for(let i=0;i<nums.length;i++){
        for(let j=i+1;j<nums.length;j++){
            if(Math.abs(nums[i]-nums[j])<=t && (Math.abs(i-j)<=k)){
                return true;
            }
        }
   }
    return false;
};