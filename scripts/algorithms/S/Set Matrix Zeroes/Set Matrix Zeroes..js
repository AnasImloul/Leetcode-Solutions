// Runtime: 75 ms (Top 29.95%) | Memory: 44.90 MB (Top 45.67%)

var setZeroes = function(matrix) {
  const rowSet = new Set(), colSet = new Set()
  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < matrix[i].length; j++) {
      if (!matrix[i][j]) {
        rowSet.add(i);
        colSet.add(j);
      };
    }
  }
  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < matrix[i].length; j++) {
      if (rowSet.has(i) || colSet.has(j)) matrix[i][j] = 0
    }
  }
};
