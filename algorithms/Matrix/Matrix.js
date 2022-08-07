/**
 * @param {number[][]} mat
 * @return {number[][]}
 */
var updateMatrix = function(mat) {
  const rows = mat.length,
        cols = mat[0].length;
  
  if (!rows) return mat;
  
  const queue = new Queue();
  const dist = Array.from({length: rows}, () => new Array(cols).fill(Infinity));
  
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      if (!mat[i][j]) {
        dist[i][j] = 0;
        queue.enqueue([i, j]);
      }
    }
  }
  
  const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
  
  while (!queue.isEmpty()) {
    const [ row, col ] = queue.dequeue();
    for (let i = 0; i < 4; i++) {
      const nRow = row + dirs[i][0],
            nCol = col + dirs[i][1];
      
      if (nRow < 0 || nCol < 0 || nRow >= rows || nCol >= cols) continue;
      
      if (dist[nRow][nCol] > dist[row][col] + 1) {
        dist[nRow][nCol] = dist[row][col] + 1;
        queue.enqueue([nRow, nCol]);
      }
    }
  }
  
  return dist;
};
