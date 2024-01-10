// Runtime: 160 ms (Top 64.29%) | Memory: 77.70 MB (Top 98.21%)

/**
 * @param {number[]} arr
 * @param {number[][]} mat
 * @return {number}
 */
var firstCompleteIndex = function(arr, mat) {
  const m = mat.length;
  const n = mat[0].length;

  const hash = {}

  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      hash[mat[i][j]] = { i, j }
    }
  }

  const rows = new Array(m).fill(0)
  const cols = new Array(n).fill(0)

  let buff;

  const last = m * n;
  for (let i = 0; i < last; i++) {
    buff = hash[arr[i]];
    rows[+buff.i]++
    cols[+buff.j]++

    if (rows[+buff.i] === n || cols[+buff.j] === m) return i
  }
};
