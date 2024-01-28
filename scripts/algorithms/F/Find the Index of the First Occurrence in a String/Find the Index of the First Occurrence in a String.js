// Runtime: 39 ms (Top 98.66%) | Memory: 49.00 MB (Top 5.15%)

var strStr = function(haystack, needle) {
    if(!needle.length) return 0;
    if(!haystack.includes(needle)) return -1;
    return haystack.split(`${needle}`)[0].length;
};
