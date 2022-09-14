// Runtime: 130 ms (Top 39.13%) | Memory: 42.1 MB (Top 82.61%)
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findKthNumber = function(m, n, k) {
  // lo always points to a value which is
  // not going to be our answer
  let lo = 0;
  let hi = m * n;

  // the loop stops when lo and hi point to two adjascent numbers
  // because lo is always incorrect, hi will contain our final answer
  while (lo + 1 < hi) {

    // As a general practice don't do a (lo + hi) / 2 because that
    // might cause integer overflow
    const mid = lo + Math.floor((hi - lo) / 2);
    const count = countLessThanEqual(mid, m, n);

    // Find the minimum mid, such that count >= k
    if (count >= k) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  return hi;
};

function countLessThanEqual(target, rows, cols) {
  let count = 0;
  // we move row by row in the multiplication table
  // Each row contains at max (target / rowIndex) elements less than
  // or equal to target. The number of cols would limit it though.
  for (let i = 1; i <= rows; i++) {
    count += Math.min(Math.floor(target / i), cols);
  }
  return count;
}