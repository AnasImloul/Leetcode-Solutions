// Runtime: 42 ms (Top 99.85%) | Memory: 52.20 MB (Top 5.11%)

/**
 * @param {character[]} chars
 * @return {number}
 */
var compress = function(chars) {
  if (!chars.length) return 0;
  let j = 0;
  let cur = chars[0];
  let counter = 0;
  for (let i = 0; i <= chars.length; i++) {
    if (chars[i] === cur) {
      counter++;
    } else {
      chars[j] = cur;
      if (counter > 1) {
        const s = counter.toString();
        for (let k = 0; k < s.length; k++) chars[++j] = s[k];
      }
      j++;
      cur = chars[i];
      counter = 1;
    }
  }
  return j;
};
