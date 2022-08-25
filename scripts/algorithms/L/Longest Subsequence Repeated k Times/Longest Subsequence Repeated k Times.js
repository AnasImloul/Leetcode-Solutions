// Runtime: 1501 ms (Top 55.56%) | Memory: 58.7 MB (Top 11.11%)
// Idea comes from:
// https://leetcode.com/problems/longest-subsequence-repeated-k-times/discuss/1471930/Python-Answer-is-not-so-long-explained

var longestSubsequenceRepeatedK = function(s, k) {
  const freq = {};
  for (const c of s) {
    if (!freq[c]) freq[c] = 0;
    freq[c]++;
  }

  // Find hot string
  let hot = "";
  for (const [c, cnt] of Object.entries(freq)) {
    const repeat = Math.floor(cnt / k);
    hot += c.repeat(repeat);
  }

  // Find all subset and permutation of hot string
  let targets = new Set();
  const subsets = getSubset(hot);
  for (const subset of subsets) {
    const permutations = getPermutation(subset);
    for (const per of permutations) targets.add(per);
  }

  // Sort targets by length and lexico
  targets = [...targets].sort((a, b) => {
    const delta = b.length - a.length;
    if (delta) return delta;
    return b.localeCompare(a);
  });

  // Filter s and check subsequence
  s = [...s].filter(c => hot.includes(c)).join("");
  for (const tar of targets) {
    if (isSubsequence(s, tar.repeat(k))) return tar;
  }

  return "";
};

function getSubset(str) {
  const res = [""];
  for (const c of str) {
    res.push(...res.map((curStr) => curStr + c));
  }
  return [...new Set(res)];
};

function getPermutation(str) {
  let res = [""];
  for (const c of str) {
    const resT = [];
    for (const cur of res) {
      for (let i = 0; i <= cur.length; i++) {
        const curT = cur.substring(0, i) + c + cur.substring(i);
        resT.push(curT);
      }
    }
    res = resT;
  }
  return [...new Set(res)];
};

function isSubsequence(s, t) {
  let i = 0;
  for (let j = 0; j < s.length; j++) {
    if (t[i] === s[j]) {
      i++;
      if (i === t.length) return true;
    }
  }
  return false;
}