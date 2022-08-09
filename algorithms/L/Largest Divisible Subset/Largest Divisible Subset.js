/** https://leetcode.com/problems/largest-divisible-subset/
 * @param {number[]} nums
 * @return {number[]}
 */
var largestDivisibleSubset = function(nums) {
  // Memo
  this.memo = new Map();
  
  // Sort the array so we can do dynamic programming from last number
  // We want to start from last number because it will be the largest number, the largest number will yield the largest subset because it can be divided many times
  nums.sort((a, b) => a - b);
  
  let out = [];
  
  // Perform dynamic programming on every numbers start from the last number
  for (let i = nums.length - 1; i >= 0; i--) {
    let curr = dp(nums, i);
    
    // Update the subset output if the current subset is larger
    if (curr.length > out.length) {
      out = curr;
    }
  }
  
  return out;
};

var dp = function(nums, currIdx) {
  // Return from memo
  if (this.memo.has(currIdx) === true) {
    return this.memo.get(currIdx);
  }
  
  let currSubset = [];
  
  // Look up all numbers before `currIdx`
  for (let i = currIdx - 1; i >= 0; i--) {
    // Check if the number at `currIdx` can be divided by number at `i`
    if (nums[currIdx] % nums[i] === 0) {
      // If they can be divided, perform dynamic programming on `i` to get the subset at `i`
      let prevSubset = dp(nums, i);
      
      // If the subset at `i` is longer than current subset, update current subset
      if (prevSubset.length > currSubset.length) {
        currSubset = prevSubset;
      }
    }
  }
  
  // Create the output which include number at `currIdx`
  let out = [...currSubset, nums[currIdx]];
  
  // Set memo
  this.memo.set(currIdx, out);
  
  return out;
};
