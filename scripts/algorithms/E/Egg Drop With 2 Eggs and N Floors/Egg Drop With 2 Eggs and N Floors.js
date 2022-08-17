/** https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/
 * @param {number} n
 * @return {number}
 */
var twoEggDrop = function(n) {
  // Writing down strategy on example 2 we can observe following pattern:
  // Drop at floor:   9   22    34    45    55    64    72    79    85    90    94    97    99    100
  // Diff from prev:      13    12    11    10    9     8     7     6     5     4     3     2     1
  
  // So we have hypothesis algorithm
  // That is, `n` minus `d` until `result(n)` is smaller than `d`, where `d` start at 1 and increment by 1 for each iteration. If `result(n)` is 0, subtract 1, else return the result
  
  let d = 1;
  
  while (n > d) {
    n -= d;
    d++;
  }
  
  if (n == 0) {
    d--;
  }
  
  return d;
};
