// Runtime: 88 ms (Top 54.97%) | Memory: 42.1 MB (Top 16.56%)
/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var sumBase = function(n, k) {
    return n.toString(k).split("").reduce((acc, cur) => +acc + +cur)
};