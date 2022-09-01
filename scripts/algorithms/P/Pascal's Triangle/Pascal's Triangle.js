// Runtime: 97 ms (Top 29.35%) | Memory: 42 MB (Top 49.80%)
var generate = function(numRows) {
    let ans = new Array(numRows)
    for (let i = 0; i < numRows; i++) {
        let row = new Uint32Array(i+1).fill(1),
            mid = i >> 1
        for (let j = 1; j <= mid; j++) {
            let val = ans[i-1][j-1] + ans[i-1][j]
            row[j] = val, row[row.length-j-1] = val
        }
        ans[i] = row
    }
    return ans
};