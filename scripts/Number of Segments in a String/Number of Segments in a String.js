/**
 * @param {string} s
 * @return {number}
 */
var countSegments = function(s) {
    return s.trim() ? s.trim().split(/\s+/).length : 0
};
