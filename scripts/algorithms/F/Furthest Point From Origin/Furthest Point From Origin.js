// Runtime: 56 ms (Top 89.4%) | Memory: 44.70 MB (Top 21.9%)

/**
 * @param {string} moves
 * @return {number}
 */
var furthestDistanceFromOrigin = function(moves) {
    let distance = 0, distance2 = 0;
    
    for (let direction of moves) {
        if (direction === 'L') distance--, distance2--;
        else if (direction === 'R') distance++, distance2++;
        else distance--, distance2++;
    }
    
    return Math.max(Math.abs(distance), Math.abs(distance2))
};