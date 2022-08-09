var maximalSquare = function(matrix) {
    let max = 0;
    const height = matrix.length-1;
    const width = matrix[0].length-1;
    for (let i=height; i>=0; i--) {
        for (let j=width; j>=0; j--) {
            const right = j < width ? Number(matrix[i][j+1]) : 0;
            const diag = i < height && j < width ? Number(matrix[i+1][j+1]) : 0
            const bottom = i < height ? Number(matrix[i+1][j]) : 0;
            matrix[i][j] = matrix[i][j] === '0' ? 0 : 
                Math.min(right, diag, bottom) + 1;
            max = Math.max(max, matrix[i][j] * matrix[i][j]);
        }  
    }
    return max;
};
