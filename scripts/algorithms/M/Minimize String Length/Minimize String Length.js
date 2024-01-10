// Runtime: 113 ms (Top 77.1%) | Memory: 50.10 MB (Top 72.05%)

/**
 * @param {string} s
 * @return {number}
 */
var minimizedStringLength = function(s) {
    const set = new Set();
    for(word of s) {
       set.add(word);
    }
    return set.size;
};
