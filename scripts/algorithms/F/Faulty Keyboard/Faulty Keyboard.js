// Runtime: 102 ms (Top 62.1%) | Memory: 48.32 MB (Top 47.2%)

var finalString = function(s) {
  let 
    str = '',
    revStr = '';

  for(let i = 0; i < s.length; i++) {
    if(s[i] === 'i') {
      [str, revStr] = [revStr, str];
    } else {
      str += s[i];
      revStr = s[i] + revStr;
    }
  }
  
  return str;
};