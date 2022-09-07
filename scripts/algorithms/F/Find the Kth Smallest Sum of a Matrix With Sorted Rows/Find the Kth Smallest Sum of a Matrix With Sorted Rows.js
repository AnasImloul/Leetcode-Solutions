// Runtime: 1870 ms (Top 17.39%) | Memory: 49.3 MB (Top 47.83%)
/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(mat, k) {
    var m = mat.length;
    var n = m ? mat[0].length : 0;
    if (!m || !n) return -1;
    var sums = [0];
    for (var idx = 0; idx < m; idx++) {
        var newSums = []
        for (var sum of sums) {
            for (var i = 0; i < n && i < k; i++) {
                var newSum = sum + mat[idx][i];
                if (newSums.length < k) {
                    newSums.push(newSum);
                } else if (newSum < newSums[k-1]) {
                    newSums.pop();
                    newSums.push(newSum);
                } else {
                    break;
                }
                newSums.sort((a, b) => a - b);
            }
        }
        sums = newSums;
    }
    return sums[k-1];
};