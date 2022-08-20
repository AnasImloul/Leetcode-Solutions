// Runtime: 89 ms (Top 44.44%) | Memory: 42 MB (Top 31.78%)

/**
 * @param {string} s
 * @return {number}
 */
var countSegments = function(s) {
    return s.trim() ? s.trim().split(/\s+/).length : 0
};