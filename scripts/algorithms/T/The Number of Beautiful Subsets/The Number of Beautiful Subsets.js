// Runtime: 625 ms (Top 55.1%) | Memory: 48.45 MB (Top 62.0%)

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var beautifulSubsets = function(nums, k) {
     //Inc Order
     nums.sort(function (a, b) {
       if (a > b) {
           return 1;
       }
       if (b > a) {
           return -1;
       }
       return 0;
      });

     function helper(i, prev, beautiful, set) {
      if (i >= nums.length) {
        if(beautiful) {
          return 1;
        }
        return 0;
      }
      let count = helper(i+1, prev, beautiful, set);
      //Check Condition
      if(Math.abs(nums[i] - prev) !== k && !set.has(nums[i] - k)) {
        set.add(nums[i]);
        count += helper(i+1, nums[i], true, set);
        set.delete(nums[i]);
      }
      return count;
    }
    let res = helper(0, -Infinity, false, new Set());
    return res;
};

