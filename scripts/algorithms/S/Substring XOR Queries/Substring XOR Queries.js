// Runtime: 334 ms (Top 60.0%) | Memory: 120.80 MB (Top 60.0%)

var substringXorQueries = function(s, queries) {
  let n = s.length, queriesMap = new Map();
  for (let i = 0; i < queries.length; i++) {
    let [first, second] = queries[i];
    queriesMap.set(first ^ second, [-1, -1]);
  }
  for (let len = 32; len >= 1; len--) {
    let val = 0;
    for (let i = 0; i < n; i++) {
      val = (val << 1) | Number(s[i]);
      if (i >= len) { 
        if ((val >> len) & 1) val = val ^ (1 << len); // remove the (i-len)th bit
      }
      if (i >= len - 1) {
        if (queriesMap.has(val)) {
          let [start, end] = queriesMap.get(val);
          let currLen = end - start + 1;
          if (currLen !== len || start === -1) {
            queriesMap.set(val, [i - len + 1, i]);
          }
        }
      }
    }
  }
  return queries.map(([first, second]) => queriesMap.get(first ^ second));
};
