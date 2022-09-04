// Runtime: 579 ms (Top 22.58%) | Memory: 89.6 MB (Top 70.97%)
var findDiagonalOrder = function(nums) {
  let vals = []; // [row, diagonal value, actual value]
  for (let i = 0; i < nums.length; i++) {
    for (let j = 0; j < nums[i].length; j++) {
      vals.push([i, i + j, nums[i][j]]);
    }
  }
  vals.sort((a, b) => {
    if (a[1] === b[1]) return b[0] - a[0];
    return a[1] - b[1];
  })
  return vals.map(val => val[2]);
};