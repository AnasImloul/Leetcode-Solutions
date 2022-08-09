/**
 * @param {number[]} arr
 * @return {number[]}
 */
var threeEqualParts = function(arr) {
  const ones = arr.reduce((s, n) => s + n, 0);
  if (ones === 0) return [0, 2];
  if (ones % 3 !== 0) return [-1, -1];
  let onesToFind = ones / 3;
  let k = arr.length;
  while (onesToFind > 0) if (arr[--k] === 1) --onesToFind;
  const iter = arr.length - k;
  const firstOne = arr.indexOf(1);
  const secondOne = arr.indexOf(1, firstOne + iter);
  for (let i = 0; i < iter; i++)
    if (arr[i + firstOne] !== arr[k + i] || arr[i + secondOne] !== arr[k + i]) return [-1, -1];
  return [firstOne + iter - 1, secondOne + iter];
};
