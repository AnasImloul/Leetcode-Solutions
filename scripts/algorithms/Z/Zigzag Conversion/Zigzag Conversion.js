// Runtime: 123 ms (Top 65.91%) | Memory: 46.7 MB (Top 68.76%)
var convert = function(s, numRows) {
  let result = [];
  let row = 0;
  let goingUp = false;
  for (let i = 0; i < s.length; i++) {
    result[row] = (result[row] || '') + s[i]; // append letter to active row
    if (goingUp) {
      row--;
      if (row === 0) goingUp = false; // reverse direction if goingUp and reaching top
    } else {
      row++;
      if (row === numRows - 1) goingUp = true; // reverse direction after reaching bottom
    }

  }
  return result.join('');
};