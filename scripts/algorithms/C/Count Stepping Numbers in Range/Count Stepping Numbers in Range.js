// Runtime: 222 ms (Top 33.33%) | Memory: 53.90 MB (Top 33.33%)

var countSteppingNumbers = function(low, high) {
  let n = high.length, memo = Array(n).fill(0).map(() => Array(10).fill(0).map(() => Array(3).fill(0).map(() => Array(3).fill(-1)))); // [n][10][3][3]
  let ans = 0, MOD = 10 ** 9 + 7;
  for (let i = 1; i <= 9; i++) {
    ans = (ans + dp(1, i, getState(0, 1, i, low), getState(0, 1, i, high))) % MOD; 
  }
  return ans;
  
  function dp(i, prev, stateLow, stateHigh) {
    if (i === high.length) return (stateLow >= 1 && stateHigh <= 1) ? 1 : 0;
    if (memo[i][prev][stateLow][stateHigh] !== -1) return memo[i][prev][stateLow][stateHigh];
    
    let ans = (i > low.length || (i === low.length && stateLow >= 1)) ? 1 : 0; // the current state is valid if the current number is within bounds of low and high
    let digits = [prev - 1, prev + 1];
    for (let digit of digits) {
      if (digit < 0 || digit > 9) continue;
      let newStateLow = getState(i, stateLow, digit, low);
      let newStateHigh = getState(i, stateHigh, digit, high);
      ans = (ans + dp(i + 1, digit, newStateLow, newStateHigh)) % MOD;
    }
    return memo[i][prev][stateLow][stateHigh] = ans;
  }  
};

function getState(i, state, digit, num) {
  if (i >= num.length) return 2; // length exceeds num, so will be greater
  if (state === 0 || state === 2) return state; // state stays the same if length is less than or equal
  if (digit > Number(num[i])) return 2; // state was the same, is greater now
  if (digit === Number(num[i])) return 1; // state was the same, and is still the same
  return 0; // state was the same, but is smaller now
}
