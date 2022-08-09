var hammingDistance = function(x, y) {
  x = x.toString(2).split('')
  y = y.toString(2).split('')
  
  let count = 0;
  const len = Math.max(x.length,y.length);

  if (x.length < y.length) {
    x = Array(len - x.length).fill('0').concat(x)
  } else {
    y = Array(len - y.length).fill('0').concat(y)
  } 

  for (let i = 1; i <= len; i++) {
    x.at(-i) !== y.at(-i)? count++ : null    
  }

  return count
};
