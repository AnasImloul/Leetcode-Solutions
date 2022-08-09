/** https://leetcode.com/problems/dice-roll-simulation/
 * @param {number} n
 * @param {number[]} rollMax
 * @return {number}
 */
var dieSimulator = function(n, rollMax) {
  // Memo
  this.memo = new Map();
  
  // Modulo
  this.mod = (10 ** 9) + 7;
  
  // Keep track of roll count for each die's face (1-6)
  let currRoll = Array(6).fill(0);
  return dp(n, rollMax, n, currRoll) % this.mod;
};

var dp = function(n, rollMax, nRemain, currRoll, previous = null) {
  let key = `${nRemain}_${currRoll.toString()}`;
  
  // Base case
  if (nRemain === 0) {
    return 1;
  }
  
  // Return from memo
  if (this.memo.has(key) === true) {
    return this.memo.get(key);
  }
  
  let count = 0;
  
  // Try every face of the die, the face is the number on the die
  // The face index in array is represented by `i`
  // The face on the die (the number) is represented by `i + 1`
  for (let i = 0; i < 6; i++) {
    // Clone object we use for tracking the roll count for each die, by cloning we don't the next recursive won't change the value of current object
    let cloneRoll = [...currRoll];
    
    // Increment the count of current face
    cloneRoll[i] += 1;
    
    // This face of the die hit limit, ignore it
    if (cloneRoll[i] > rollMax[i]) {
      continue;
    }
    
    // This face of the die is different that previous one, since the limit is only for consecutive count, it means the previous face's count should be reset
    if (previous != null && i + 1 != previous) {
      cloneRoll[previous - 1] = 0;
    }
    
    // Count next recursive
    count += dp(n, rollMax, nRemain - 1, cloneRoll, i + 1) % this.mod;
  }

  // Set memo
  this.memo.set(key, count);
  
  return count;
};
