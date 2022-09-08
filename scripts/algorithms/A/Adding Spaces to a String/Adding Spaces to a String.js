// Runtime: 206 ms (Top 91.18%) | Memory: 83.4 MB (Top 96.08%)
/**
 * @param {string} s
 * @param {number[]} spaces
 * @return {string}
 */
var addSpaces = function(s, spaces) {
    let words = spaces.map((space, index) => s.slice(index == 0 ? 0 : spaces[index-1], space));
    words.push(s.slice(spaces[spaces.length-1]));
    return words.join(' ');
};