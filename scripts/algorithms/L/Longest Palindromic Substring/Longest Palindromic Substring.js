// Runtime: 59 ms (Top 26.83%) | Memory: 67.70 MB (Top 9.40%)

function longestPalindrome(s) {
  let ll = 0, rr = 0;

  for (let i = 0; i < s.length; i++)
    for (let j of [i, i+1])
      for (l = i, r = j; s[l] && s[l] === s[r]; l--, r++)
        [ll, rr] = (r-l+1) > (rr-ll+1) ? [l, r] : [ll, rr];

  return s.substring(ll, rr+1);
}
