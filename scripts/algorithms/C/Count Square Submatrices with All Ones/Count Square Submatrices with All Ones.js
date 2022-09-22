// Runtime: 150 ms (Top 40.00%) | Memory: 45.7 MB (Top 65.81%)
var countSquares = function(matrix) {
    let m = matrix.length;
    let n = matrix[0].length;

    while(matrix){
        let preCount = 0;
        let count = 0;
        for(let i = 0; i < m; i++){
            for(let j = 0; j < n; j++){
                preCount += matrix[i][j];
                if(i + 1 < m && j + 1 < n){
                    if(matrix[i][j] != 0
                       &&matrix[i][j] == matrix[i + 1][j]
                       && matrix[i][j] == matrix[i][j + 1]
                       && matrix[i][j] == matrix[i + 1][j + 1]) matrix[i][j]++;
                }
                count += matrix[i][j];
            }
        }
        if(preCount == count) return count;
    }
};