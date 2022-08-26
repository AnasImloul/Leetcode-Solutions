// Runtime: 158 ms (Top 82.00%) | Memory: 53.8 MB (Top 52.00%)
var minSteps = function(s, t) {
  let sFreq = Array(26).fill(0), tFreq = Array(26).fill(0);
  for (let char of s) sFreq[char.charCodeAt() - 97]++;
  for (let char of t) tFreq[char.charCodeAt() - 97]++;
  let ans = 0;
  for (let i = 0; i < 26; i++) {
    ans += Math.abs(sFreq[i] - tFreq[i]);
  }
  return ans;
};