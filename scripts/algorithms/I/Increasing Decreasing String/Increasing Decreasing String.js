// Runtime: 160 ms (Top 30.26%) | Memory: 45.8 MB (Top 75.00%)
/**
 * @param {string} s
 * @return {string}
 */
var sortString = function(s) {
  const counts = [...s].reduce((acc, cur) => (acc[cur.charCodeAt() - 97] += 1, acc), new Array(26).fill(0));
  const result = [];

  const pick = (code) => {
    if (counts[code]) {
      result.push(String.fromCharCode(code + 97));
      counts[code] -= 1;
    }
  }

  while (result.length < s.length) {
    for (let i = 0; i < counts.length; i++) pick(i);
    for (let i = 0; i < counts.length; i++) pick(counts.length - 1 - i);
  }

  return result.join('');
};