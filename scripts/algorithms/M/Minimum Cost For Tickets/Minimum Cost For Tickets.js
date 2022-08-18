// Runtime: 110 ms (Top 36.61%) | Memory: 44.6 MB (Top 25.14%)

var mincostTickets = function(days, costs) {
  let store = {};
  for(let i of days) {
      store[i] = true
  }
  let lastDay = days[days.length - 1]
  let dp = new Array(days[days.length - 1] + 1).fill(Infinity);
  dp[0] = 0;

  for(let i = 1; i< days[days.length - 1] + 1; i++) {
      if(!store[i]) {
          dp[i] = dp[i-1];
          continue;
      }
      dp[i] = costs[0] + dp[i-1];
      dp[i] = Math.min(costs[1] + dp[Math.max(i - 7, 0)], dp[i]);
      dp[i] = Math.min(costs[2] + dp[Math.max(i - 30, 0)], dp[i]);
  }

  return dp[lastDay]

};