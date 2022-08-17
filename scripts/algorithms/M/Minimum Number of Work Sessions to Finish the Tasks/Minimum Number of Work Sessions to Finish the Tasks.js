/**
 * @param {number[]} tasks
 * @param {number} sessionTime
 * @return {number}
 */
var minSessions = function(tasks, sessionTime) {
  const n = tasks.length;
  const dp = Array(1 << n).fill().map(() => Array(16).fill(-1));
  
  const solve = (mask, time) => {
    if (mask === (1 << n) - 1) {
      return 1;
    }
    
    if (dp[mask][time] !== -1) {
      return dp[mask][time];
    }
    
    let min = Infinity;
    for (let i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        continue;
      }

      if (time >= tasks[i]) {
        min = Math.min(
          min,
          solve(mask | (1 << i), time - tasks[i]),
        );
      } else {
        min = Math.min(
          min,
          1 + solve(mask | (1 << i), sessionTime - tasks[i]),
        );
      }
    }
    
    dp[mask][time] = min;
    return min;
  }
  
  return solve(0, sessionTime);
};

