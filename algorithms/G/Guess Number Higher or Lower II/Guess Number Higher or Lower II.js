/** https://leetcode.com/problems/guess-number-higher-or-lower-ii/
 * @param {number} n
 * @return {number}
 */
var getMoneyAmount = function(n) {
  // Memo
  this.memo = new Map();
  
  return dp(n, 0, n);
};

var dp = function(n, start, end) {
  let key = `${start}_${end}`;
  
  // Base, there is only 1 node on this side of the leg, which mean our guess is always correct and it cost nothing so return 0
  if (end - start < 2) {
    return 0;
  }
  
  // Base, there are only 2 nodes on this side of the leg, which mean we only need to pick cheapest guess
  if (end - start === 2) {
    // The `start` will always be smaller so pick `start`, add 1 to account for 0 index
    return start + 1;
  }
  
  // Return from memo
  if (this.memo.has(key) === true) {
    return this.memo.get(key);
  }
  
  // Minimum cost
  let minCost = Infinity;
  
  // Try to arrange the tree's left and right leg and find the cost of each leg
  for (let i = start; i < end; i++) {
    let left = dp(n, start, i);
    let right = dp(n, i + 1, end);
    
    // Cost of current guess, add 1 to account for 0 index
    let curr = i + 1;
    
    // Update cost of current guess, which is the max of left or right leg
    curr = Math.max(left + curr, right + curr);
    
    // Then update the minimum cost for entire tree
    minCost = Math.min(minCost, curr);
  }
  
  // Set memo
  this.memo.set(key, minCost);
  
  return minCost;
};
