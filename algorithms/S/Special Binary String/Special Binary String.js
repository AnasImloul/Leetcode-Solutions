var makeLargestSpecial = function(s) {
  return recurse(s);
  
  function recurse(s) {
    let i = 0, res = [], bal = 0;
    for (let j = 0; j < s.length; j++) {
      if (s[j] === '1') bal++;
      else bal--;
      if (bal === 0) { // found a balanced special substring
        res.push('1' + recurse(s.slice(i + 1, j)) + '0'); // s[i] must be 1 and s[j] must be 0, if 1...1, it would be invalid.
        i = j + 1; // go to next start position
      }
    }
    res.sort((a, b) => b.localeCompare(a)); // sort substrings in desc order
    return res.join(""); 
  }
};
