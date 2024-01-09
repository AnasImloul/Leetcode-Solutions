// Runtime: 85 ms (Top 62.71%) | Memory: 50.10 MB (Top 44.92%)

/**
 * @param {number[][]} mat
 * @return {number[]}
 */
var rowAndMaximumOnes = function(mat) {
    const ans = [0, 0]
    mat.forEach((row, i) => {
        const count = row.reduce((a, b) => a + b, 0)
        if (count > ans[1]) {
            ans[0] = i
            ans[1] = count
        }
    })
    return ans
};
