// Runtime: 133 ms (Top 16.61%) | Memory: 42.3 MB (Top 87.95%)
/**
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 */
var selfDividingNumbers = function(left, right) {
  const selfDivisibles = [];
  for (let i = left; i <= right; i++) {
    if (checkDivisibility(i)) {
      selfDivisibles.push(i);
    }
  }
  return selfDivisibles;
};

function checkDivisibility(num) {
  let status = true;
  let mod;
  let original = num;
  while (num !== 0) {
    mod = Math.trunc(num % 10);
    if (original % mod !== 0) {
      status = false;
      break;
    }
    num = Math.trunc(num / 10);
  }
  return status;
}