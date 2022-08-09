var spellchecker = function(wordlist, queries) {
  const baseList = new Set(wordlist.reverse());
  const loweredList = wordlist.reduce((map, word) => (map[normalize(word)] = word, map), {});
  const replacedList = wordlist.reduce((map, word) => (map[repVowels(word)] = word, map), {});
  return queries.map(word => (
    baseList.has(word) && word    ||
	loweredList[normalize(word)]  ||
	replacedList[repVowels(word)] ||
	''
  ));
};
var normalize = function(word) { return word.toLowerCase() };
var repVowels = function(word) { return normalize(word).replace(/[eiou]/g, 'a') };
