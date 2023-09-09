// Runtime: 52 ms (Top 96.5%) | Memory: 44.02 MB (Top 77.0%)

var myAtoi = function(str) {
    return Math.max(Math.min(parseInt(str) || 0, 2147483647), -2147483648)
};