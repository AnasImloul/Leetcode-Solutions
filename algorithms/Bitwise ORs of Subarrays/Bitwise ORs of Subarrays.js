/** https://leetcode.com/problems/bitwise-ors-of-subarrays/
 * @param {number[]} arr
 * @return {number}
 */
var subarrayBitwiseORs = function(arr) {
  // Hashset to store the unique bitwise
  this.uniqueBw = new Set();
  
  // Dynamic programming
  dp(arr, arr.length - 1);
  
  return this.uniqueBw.size;
};

var dp = function(arr, currIdx) {
  // Base, reach beginning of the array
  if (currIdx === 0) {
    // Store the value to unique bitwise, since it's only single number, we store the actual value
    this.uniqueBw.add(arr[0]);
    
    // Return array
    return [arr[0]];
  }
  
  // DP to previous index
  let prev = dp(arr, currIdx - 1);
  
  // Number at current index
  let firstBw = arr[currIdx];
  
  // Add number at current index to hashset, since it's only single number, we store the actual value
  this.uniqueBw.add(firstBw);
  
  // Another hashset to store the result of bitwise operation between number at current index with result from previous index
  let currRes = new Set();
  currRes.add(firstBw);
  
  // Loop through result form previous index
  for (let i = 0; i < prev.length; i++) {
    // Perform bitwise operation OR
    let curr = arr[currIdx] | prev[i];
    
    // Add to unique bitwise collection
    this.uniqueBw.add(curr);
    
    // Add to current result
    currRes.add(curr);
  }

  // Return current result as an array
  return [...currRes];
};
