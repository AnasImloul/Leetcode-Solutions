// Runtime: 63 ms (Top 13.04%) | Memory: 42.60 MB (Top 28.26%)

var generateTheString = function(n) {
    return n%2 ? new Array(n).fill('a').join('') : new Array(n - 1).fill('a').join('') + 'b';
};
