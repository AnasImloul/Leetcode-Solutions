// Runtime: 119 ms (Top 68.89%) | Memory: 44.2 MB (Top 75.56%)
/**
 * @param {string} word
 * @return {number}
 */
var isVowel = function(c) {
    return (c === 'a' || c === 'e' || c === 'i' || c === 'o' || c === 'u');
}

var countVowelSubstrings = function(word) {
    let vowelMap = new Map();
    let total = 0;
    let totalLen = word.length - 1;
    for(let i = 0 ; i <= totalLen; i++){
        vowelMap.clear();
        for(let j = i; j <= totalLen && isVowel(word[j]); j++){
            vowelMap.set(word[j], (vowelMap.get(word[j]) ?? 0) + 1);
            if(vowelMap.size == 5)
                total++;
        }
    }
    return total;
};