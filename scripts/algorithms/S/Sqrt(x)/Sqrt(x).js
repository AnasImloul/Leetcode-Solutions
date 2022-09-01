// Runtime: 112 ms (Top 59.43%) | Memory: 43.6 MB (Top 60.45%)
/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    const numx = x;
    let num = 0;

    while (num <= x) {
        const avg = Math.floor((num+x) / 2);
        if (avg * avg > numx) x = avg - 1;
        else num = avg + 1;
    }
    return x;
};
