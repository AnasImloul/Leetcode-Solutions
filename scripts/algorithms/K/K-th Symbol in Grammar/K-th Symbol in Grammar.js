// Runtime: 102 ms (Top 22.47%) | Memory: 41.5 MB (Top 88.20%)
/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var kthGrammar = function(n, k) {
    if (n == 1 && k == 1) {
        return 0;
    }

    const mid = Math.pow(2, n-1) / 2;

    if (k <= mid) {
        return kthGrammar(n-1, k);
    } else {
        return kthGrammar(n-1, k-mid) == 1 ? 0 : 1;
    }
};
