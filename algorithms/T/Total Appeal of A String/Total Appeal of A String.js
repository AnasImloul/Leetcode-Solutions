var appealSum = function(s) {
  let ans = 0, n = s.length;
  let lastIndex = Array(26).fill(-1);
  for (let i = 0; i < n; i++) {
    let charcode = s.charCodeAt(i) - 97;
    let lastIdx = lastIndex[charcode];
    ans += (n - i) * (i - lastIdx);
    lastIndex[charcode] = i;
  }  
  return ans;
};
