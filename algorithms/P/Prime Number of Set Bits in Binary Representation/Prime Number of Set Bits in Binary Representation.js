var countPrimeSetBits = function(left, right) {
  let ans = 0;

  // The `outer` is valid javascript syntax, just not well-known: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/label
  outer:
  for(let i = left; i <= right; i++) {
    let num = i;
    let numBits = 0;
    while(num) {
      numBits++;
      num &= num-1;
    }
    
    if(numBits === 1) continue outer;
    for(let j = 2; j <= Math.floor(Math.sqrt(numBits)); j++) {
      if(numBits % j === 0) continue outer;
    }
      
    ans++;
  }
  
  return ans;
};
