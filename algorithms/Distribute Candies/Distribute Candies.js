/**
 * @param {number[]} candyType
 * @return {number}
 */
var distributeCandies = function(candyType) {
    
    const set = new Set();
    candyType.map(e => set.add(e));
    return candyType.length/2 > set.size ? set.size : candyType.length/2
    
};

