/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var orderlyQueue = function(s, k) {
  // rotate the string one by one, and check which is lexographically smaller
  if (k === 1) {
    let temp = `${s}`;
    let smallest = `${s}`;
    let count = 0;
    while (count < s.length) {
      temp = temp.substring(1, s.length) + temp.charAt(0);
      if (temp < smallest) {
        smallest = temp;
      }
      count++;
    }
    return smallest;
  }
  
  // if k is greater than 1, any permutation is possilbe
  // so we simply return the sorted string (convert to array -> sort -> back to string)
  if (k > 1) {
    return [...s].sort().join('');
  }
  
  return s;
};
