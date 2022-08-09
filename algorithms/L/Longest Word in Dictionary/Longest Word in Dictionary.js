var longestWord = function(words) {
  words.sort();
  let trie = new Trie();
  let result = ""
  
  for (const word of words) {
      if (word.length === 1) {
          trie.insert(word);
          result = word.length > result.length ? word : result;
      } else {
          let has = trie.search(word.slice(0, word.length-1));
          if (has) {
              trie.insert(word);
              result = word.length > result.length ? word : result;
          }
      }
  }
  
  return result;
};
