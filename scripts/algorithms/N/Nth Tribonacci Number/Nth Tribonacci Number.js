// Runtime: 50 ms (Top 63.89%) | Memory: 41.50 MB (Top 76.83%)

/**
 * @param {number} n
 * @return {number}
 */
var tribonacci = function(n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    const seq = [0, 1, 1]
    for (let i=3; i<=n; i++) {
        seq.push(seq[0] + seq[1] + seq[2]);
        seq.shift();
    }
    return seq[2];
};
