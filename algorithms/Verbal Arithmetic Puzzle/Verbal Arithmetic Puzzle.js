/**
 * @param {string[]} words
 * @param {string} result
 * @return {boolean}
 */
var isSolvable = function(words, result) {
  // set to hold all the first characters
  const firstChars = new Set();
  
  // map for steps 1 & 2
  // this will hold the key as the character and multiple as the value
  let map = {};
  for (let i = 0; i < result.length; i++) {
      const char = result[i];
      if (!i) firstChars.add(char);
      if (!map.hasOwnProperty(char)) map[char] = 0;
      map[char] -= 10 ** (result.length - i - 1);
    }
    for (let j = 0; j < words.length; j++) {
      const word = words[j];
      for (let i = 0; i < word.length; i++) {
        const char = word[i];
        if (!i) firstChars.add(char);
        if (!map.hasOwnProperty(char)) map[char] = 0;
        map[char] += 10 ** (word.length - i - 1);
      }
  }
  
  // Step 3: we group the positive and negative values
  const positives = [];
  const negatives = [];
  Object.entries(map).forEach((entry) => {
    if (entry[1] < 0) negatives.push(entry);
    else positives.push(entry);
  })

  // Step 4: backtrack
  const numsUsed = new Set();
  const backtrack = (val = 0) => {
    // if we have used all the characters and the value is 0 the input is solvable
    if (!positives.length && !negatives.length) return val === 0;
	
	// get the store that we are going to examine depending on the value
    let store = val > 0 || (val === 0 && negatives.length) ? negatives : positives;
    if (store.length === 0) return false;
    const entry = store.pop();
    const [char, multiple] = entry;
	
	// try every possible value watching out for the edge case that it was a first character
    for (let i = firstChars.has(char) ? 1 : 0; i < 10; i++) {
      if (numsUsed.has(i)) continue;
      numsUsed.add(i);
      if (backtrack(i * multiple + val)) return true;
      numsUsed.delete(i);
    }
    store.push(entry);
    return false;
  }
  return backtrack();
};
