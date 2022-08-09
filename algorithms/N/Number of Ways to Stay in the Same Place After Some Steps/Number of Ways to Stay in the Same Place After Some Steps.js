var numWays = function(steps, arrLen) {
  let memo = Array(steps + 1).fill(0).map(() => Array(steps + 1).fill(-1)), mod = 10 ** 9 + 7;
  return dp(0, steps);
  
  function dp(i, steps) {
    if (steps === 0) return i === 0 ? 1 : 0; // found a way
    if (i > steps || i < 0 || i >= arrLen) return 0; // out of bounds
    if (memo[i][steps] !== -1) return memo[i][steps]; // memoized
    
    let moveLeft = dp(i - 1, steps - 1);
    let moveRight = dp(i + 1, steps - 1);
    let stay = dp(i, steps - 1);
    return memo[i][steps] = (moveLeft + moveRight + stay) % mod;
  }
};
