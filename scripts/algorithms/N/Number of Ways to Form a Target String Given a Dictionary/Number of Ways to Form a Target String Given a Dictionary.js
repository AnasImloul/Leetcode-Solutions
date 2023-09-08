// Runtime: 1314 ms (Top 12.2%) | Memory: 96.26 MB (Top 38.6%)

/**
 * @param {string[]} words
 * @param {string} target
 * @return {number}
 */
var numWays = function(words, target) {
  const targetLength = target.length;
  const wordsLength = words.length;
  const wordLength = words[0].length;
  const mem = Array(targetLength).fill(0).map(() => Array(targetLength));

  const count = Array(26).fill(0).map(() => ({}));
  for (let i = 0; i < wordsLength; i++) {
    for (let j = 0; j < wordLength; j++) {
      if (!count[words[i].charCodeAt(j) - 97][j]) {
        count[words[i].charCodeAt(j) - 97][j] = 0;
      }
      count[words[i].charCodeAt(j) - 97][j]++;
    }
  }

  const dp = (targetIndex, minIndex) => {
    if (targetIndex === targetLength) {
      return 1;
    }
    if (wordLength - minIndex < targetLength - targetIndex) return 0;
    if (mem[targetIndex][minIndex] !== undefined) 
      return mem[targetIndex][minIndex];
    let res = 0;
    
    for (let i = minIndex; i < wordLength; i++) {
      if (count[target.charCodeAt(targetIndex) - 97][i]) {
        res += Number(count[target.charCodeAt(targetIndex) - 97][i])
          * dp(targetIndex + 1, i + 1);
      }
    }

    res %= (1e9 + 7);
    mem[targetIndex][minIndex] = res;
    return res;
  }

  return dp(0, 0);
};