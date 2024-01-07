// Runtime: 72 ms (Top 93.58%) | Memory: 45.60 MB (Top 97.33%)

var similarPairs = function(words) {
  let count = new Map(), ans = 0;
  for (let word of words) {
    let mask = getMask(word);
    let occurances = count.get(mask) || 0;
    ans += occurances;
    count.set(mask, occurances + 1);
  }
  return ans;
};

function getMask(word) {
  let mask = 0;
  for (let i = 0; i < word.length; i++) {
    let charcode = word[i].charCodeAt() - 97;
    mask |= (1 << charcode);
  }
  return mask;
}
