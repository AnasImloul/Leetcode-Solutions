/**
 * @param {number[]} tops
 * @param {number[]} bottoms
 * @return {number}
 */
var minDominoRotations = function(tops, bottoms) {
    const swaps = Math.min(
        minimum(tops[0], tops, bottoms),
        minimum(tops[0], bottoms, tops),
        minimum(bottoms[0], tops, bottoms),
        minimum(bottoms[0], bottoms, tops)
    );

    return swaps === Infinity ? -1 : swaps;

    function minimum(target, x, y, count = 0) {
        for(let i = 0; i < x.length; i++) {
            if(target !== x[i]) {
                if (target !== y[i]) return Infinity
                count++;
            }
        }
        return count;
    }
};
