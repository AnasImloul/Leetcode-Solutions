var uniqueLetterString = function(s) {
  
  // Returns the number of unique characters inside the window [left, right]
  const countUniqueCharacters = (left, right) => {
    const counts = new Map();
    for (let i = left; i < right; i += 1) {
      counts.set(s[i], (counts.get(s[i]) || 0) + 1);
    }
    return Array.from(counts.values()).filter((x) => x === 1).length;
  }; 
  
  let sum = 0;
  const seen = new Set();
  const substring = (left, right) => {
    
    if (seen.has(`${left}, ${right}`)) return;
    if (right - left <= 0) return;
    
    seen.add(`${left}, ${right}`);
    
    sum += countUniqueCharacters(left, right);
    
    for (let i = left; i < right; i += 1) {
      substring(left + 1, right);
      substring(left, right - 1);
    }
  };
  
  substring(0, s.length);
  return sum;
};
