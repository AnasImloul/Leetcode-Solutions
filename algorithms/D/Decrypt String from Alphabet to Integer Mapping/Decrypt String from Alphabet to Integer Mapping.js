
var freqAlphabets = function(s) {
  const ans = []
  for (let i = 0, len = s.length; i < len; ++i) {
    const c = s.charAt(i)
    if (c === '#') {
      ans.length = ans.length - 2
      ans.push(String.fromCharCode(parseInt(`${s.charAt(i - 2)}${s.charAt(i - 1)}`, 10) + 96))
      continue
    }
    ans.push(String.fromCharCode(+c + 96))
  }
  return ans.join('')
};
