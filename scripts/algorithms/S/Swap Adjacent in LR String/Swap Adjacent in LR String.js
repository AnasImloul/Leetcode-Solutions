// Runtime: 125 ms (Top 32.14%) | Memory: 42.9 MB (Top 73.21%)
/**
 * @param {string} start
 * @param {string} end
 * @return {boolean}
 */
var canTransform = function(start, end) {
    let i = 0;
    let j = 0;

    while (i < start.length || j < end.length) {
        if (start[i] === 'X') {
            i++;
            continue;
        }

        if (end[j] === 'X') {
            j++;
            continue;
        }

        // Breaking (1)
        if (start[i] !== end[j]) return false;

        // Breaking (2)
        if (start[i] === 'R' && i > j) return false;

        // Breaking (3)
        if (start[i] === 'L' && j > i) return false;

        i++;
        j++;
    }

    return true;
};