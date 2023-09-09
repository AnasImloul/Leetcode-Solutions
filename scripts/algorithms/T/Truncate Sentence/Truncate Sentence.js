// Runtime: 51 ms (Top 67.8%) | Memory: 41.86 MB (Top 66.1%)

/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var truncateSentence = function(s, k) {
   return s.split(" ").slice(0,k).join(" ")
};