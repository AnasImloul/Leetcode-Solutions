 * @param {number} n
 * @return {number}
 */
var reinitializePermutation = function(n) {
  if (n < 2) return 0;
  let prem = [];
  let count = 0;
  for (var i = 0; i < n; i++) {
    prem[i] = i;
  }
  let newArr = [];
  newArr = helper(prem, newArr);

  const equals = (a, b) => JSON.stringify(a) === JSON.stringify(b);

  if (equals(prem, newArr)) {
    count++;
    return count;
  } else {
    while (!equals(prem, newArr)) {
      count++;
      let temp = newArr;
      newArr = [];
      newArr = helper(temp, newArr);
    }
  }
  return count + 1;
};

var helper = function (prem, arr) {
  let n = prem.length;
  for (var i = 0; i < n; i++) {
    if (i % 2 == 0) {
      arr[i] = prem[i / 2];
    } else {
      arr[i] = prem[n / 2 + (i - 1) / 2];
    }
  }
  return arr;
};
