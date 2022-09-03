// Runtime: 120 ms (Top 24.96%) | Memory: 43.9 MB (Top 40.35%)
var countKDifference = function(nums, k) {
    nums = nums.sort((b,a) => b- a)
   let count = 0;

    for(let i = 0; i< nums.length; i++) {
         for(let j = i + 1; j< nums.length; j++) {
            if(Math.abs(nums[i] - nums[j]) == k) {
                count++
            }
          }
    }
    return count ;
};