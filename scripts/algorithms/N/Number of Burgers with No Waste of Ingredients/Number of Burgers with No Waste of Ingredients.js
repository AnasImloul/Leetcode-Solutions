// Runtime: 117 ms (Top 64.71%) | Memory: 44.5 MB (Top 5.88%)
/**
 * @param {number} tomatoSlices
 * @param {number} cheeseSlices
 * @return {number[]}
 */
var numOfBurgers = function(tomatoSlices, cheeseSlices) {
    if (tomatoSlices & 1) return []; // return [] if tomatoSlices is odd
    const j = (tomatoSlices >> 1) - cheeseSlices; // jumbo = (tomatoSlices / 2) - cheeseSlices
    return j < 0 || j > cheeseSlices ? [] : [j, cheeseSlices - j]; // small = cheeseSlices - jumbo, if any of jmbo and small < 0 return [] otherwise return [jumbo, small]
};