var isToeplitzMatrix = function(matrix) {
    for (let i=0; i < matrix.length-1; i++) {
        for (let j=0; j < matrix[i].length-1; j++) {    
            if (matrix[i][j] !== matrix[i+1][j+1]) {
                return false
            }
        }
    }
    
    return true
};
