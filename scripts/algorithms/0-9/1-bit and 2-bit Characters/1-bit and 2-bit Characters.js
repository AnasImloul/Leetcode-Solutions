// Runtime: 101 ms (Top 27.55%) | Memory: 42.2 MB (Top 67.35%)
/**
 * @param {number[]} bits
 * @return {boolean}
 */
var isOneBitCharacter = function(bits) {
  let i = 0;
  while (i < bits.length - 1) {
    if (bits[i] === 1) i++;
    i++;
  }
  return bits[i] === 0;
};