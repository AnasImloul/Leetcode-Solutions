// Runtime: 421 ms (Top 13.84%) | Memory: 55.5 MB (Top 89.23%)
var maxIceCream = function(costs, coins) {
  costs.sort((a, b) => a - b);
  let count = 0;

  for (let i = 0; i < costs.length; i++) {
    if (costs[i] <= coins) {
      count++;
      coins -= costs[i]
    } else {
      break; // a small optimization, end the loop early if coins go down to zero before we reach end of the length of costs.
    }
  }
  return count;
};