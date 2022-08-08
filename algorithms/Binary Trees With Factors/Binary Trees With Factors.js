/** https://leetcode.com/problems/binary-trees-with-factors/
 * @param {number[]} arr
 * @return {number}
 */
var numFactoredBinaryTrees = function(arr) {
  // Memo
  this.memo = new Map();
  
  // Sort the `arr`
  arr.sort((a, b) => a - b);
  
  // Create hashmap so we can easily find the index of the value
  let map = new Map();
  arr.forEach((val, idx) => map.set(val, idx));
  
  // We are going to calculate total numbers of binary trees by assigning each `arr[i]` as the root of the tree
  let count = 0;
  for (let i = arr.length - 1; i >= 0; i--) {
    count += dp(arr, map, i);
  }
  
  // Perform mod on the final result
  let mod = (10 ** 9) + 7;
  return count % mod;
};

var dp = function(arr, map, currIdx) {
  // Return from memo
  if (this.memo.has(currIdx) === true) {
    return this.memo.get(currIdx);
  }
  
  // Start the count as 1 to include the current node
  let count = 1;
  
  // Loop through all number before `arr[currIdx]`
  for (let i = currIdx - 1; i >= 0; i--) {
    // The `left` and `right` node of the root
    // The `right` node is basically the root divided by the `left` since the rule stated that the root is product of its children
    let left = arr[i];
    let right = arr[currIdx] / left;
    
    // Ignore if the root is not a product of its children
    if (arr[currIdx] % left !== 0 ||
       map.has(right) === false) {
      continue;
    }
    
    // Get the count for `left` node and `right` node
    let leftCount = dp(arr, map, i);
    let rightCount = dp(arr, map, map.get(right));
    
    // Total count is multiplication of `left` and `right` count because each combination of is unique
    count += leftCount * rightCount;
  }
  
  // Set memo
  this.memo.set(currIdx, count);
  
  return count;
};
