// Runtime: 62 ms (Top 95.54%) | Memory: 42.3 MB (Top 53.45%)
var uniquePaths = function(m, n) {
    let count = Array(m)
    for(let i=0; i<m; i++) count[i] = Array(n)
    for(let i=0; i<m; i++){
        for(let j=0; j<n; j++){
            if(i == 0 || j == 0) count[i][j] = 1
            else count[i][j] = count[i][j-1] + count[i-1][j]
        }
    }
    return count[m-1][n-1]
};