
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

