/**
 * @param {number} n
 * @return {boolean}
 */
var hasAlternatingBits = function(n) {
  let previous;
  while (n) {
    const current = n & 1;
    if (previous === current) return false;
    previous = current;
    n >>>= 1;
  }
  return true;
};
