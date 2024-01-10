// Runtime: 48 ms (Top 83.84%) | Memory: 42.00 MB (Top 45.45%)

/**
 * @param {string} s
 * @return {string}
 */
var freqAlphabets = function(s) {
    return s
        .match(/\d{2}(?=#)|\d/g)
        .map(num => String.fromCharCode(96 + +num))
        .join('')
};
