// Runtime: 101 ms (Top 40.82%) | Memory: 43.3 MB (Top 79.80%)
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