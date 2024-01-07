// Runtime: 49 ms (Top 97.08%) | Memory: 44.30 MB (Top 78.72%)

var decodeMessage = function(key, message) {
  let result = ''
  key = Array.from(new Set(key.split(' ').join('')))
  const hash = new Map()
  const alpha = 'abcdefghijklmnopqrstuvwxyz'
  
  for (let i = 0; i < alpha.length; i++) {
    hash.set(key[i], alpha[i])
  }

  for (let chr of message) {
    result += hash.get(chr) || ' '
  }
    
  return result
};

