// Runtime: 222 ms (Top 37.27%) | Memory: 56.5 MB (Top 32.38%)
/**
 * @param {number[]} candyType
 * @return {number}
 */
var distributeCandies = function(candyType) {

    const set = new Set();
    candyType.map(e => set.add(e));
    return candyType.length/2 > set.size ? set.size : candyType.length/2

};
