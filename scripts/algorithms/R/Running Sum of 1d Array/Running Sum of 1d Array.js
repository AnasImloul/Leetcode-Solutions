// Runtime: 89 ms (Top 55.72%) | Memory: 42.9 MB (Top 15.89%)
/**
 * @param {number[]} nums
 * @return {number[]}
 */

var runningSum = function(nums) {
  let res = [];
  let a = 0;
  for (let i = 0; i < nums.length; i++) {
    res[i] = a + nums[i];
    a = res[i];
    if(res.length < nums.length){
    res.push(a);
    }
  }
return res;
};