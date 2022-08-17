var diagonalSum = function(mat) {   
    return mat.reduce((acc, matrix, i)=>{
      const matrixlength = matrix.length-1;
       return acc += (i !== matrixlength-i) ? matrix[i]+ matrix[matrixlength-i] : matrix[i];
    },0)
};

/*
Runtime: 67 ms, faster than 92.84% of JavaScript online submissions for Matrix Diagonal Sum.
Memory Usage: 42.9 MB, less than 88.29% of JavaScript online submissions for Matrix Diagonal Sum.
*/