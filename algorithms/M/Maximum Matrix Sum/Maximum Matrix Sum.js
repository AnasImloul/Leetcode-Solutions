var maxMatrixSum = function(matrix) {
    const MAX= Number.MAX_SAFE_INTEGER;
    
    const m = matrix.length;
    const n = matrix[0].length;
    
    let negs = 0;
    
    let totAbsSum = 0;
    let minAbsNum = MAX;
    
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (matrix[i][j] < 0) ++negs;
            
            totAbsSum += Math.abs(matrix[i][j]);
            minAbsNum = Math.min(minAbsNum, Math.abs(matrix[i][j]));
        }
    }
    
    if (negs % 2 === 1) totAbsSum -= (2 * minAbsNum);
    
	return totAbsSum;
};
