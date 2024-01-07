// Runtime: 52 ms (Top 62.71%) | Memory: 41.80 MB (Top 53.44%)

/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    let value = x ^ y;
    let counter = 0;
    
    while (value != 0) {
        if (value & 1)
           ++counter
           
        value = value >> 1
    }
    
    return counter
};
