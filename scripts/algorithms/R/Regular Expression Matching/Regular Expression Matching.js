// Runtime: 515 ms (Top 10.50%) | Memory: 56.50 MB (Top 64.08%)

/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */

var isMatch = function(s, p) {
    const pattern = new RegExp('^'+p+'$'); // ^ means start of string, $ means end of the string, these are to prevent certain pattern that match a part of the string to be returned as true.
    return pattern.test(s);
};
