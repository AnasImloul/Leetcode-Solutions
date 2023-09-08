// Runtime: 181 ms (Top 84.2%) | Memory: 56.68 MB (Top 15.7%)

/**
 * @param {number} bottom
 * @param {number} top
 * @param {number[]} special
 * @return {number}
 */
var maxConsecutive = function(bottom, top, special) {
    special.push(top+1);
    special.push(bottom-1);
    special.sort((a, b) => a - b);
    let specialMax = 0;
    for (let i = 1; i < special.length; i++){
        specialMax = Math.max(specialMax, special[i] - special[i-1] - 1)
    }
    return specialMax;
};