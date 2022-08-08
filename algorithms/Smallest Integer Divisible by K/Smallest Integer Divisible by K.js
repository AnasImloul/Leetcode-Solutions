/**
 * @param {number} k
 * @return {number}
 */
var smallestRepunitDivByK = function(k) {
    if( 1 > k > 1e6 ) return -1;
    let val = 0;
    for (let i = 1; i < 1e6; i++) {
        val = (val * 10 + 1) % k;
        if (val === 0) return i;
    }
    return -1;
};
