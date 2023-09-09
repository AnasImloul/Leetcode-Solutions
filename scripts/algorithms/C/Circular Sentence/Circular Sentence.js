// Runtime: 40 ms (Top 97.3%) | Memory: 42.12 MB (Top 57.6%)

/**
 * @param {string} sentence
 * @return {boolean}
 */
var isCircularSentence = function(sentence) {
    const words = sentence.split(' ');
    const lastWord = words[words.length - 1];
    let lastChar = lastWord[lastWord.length - 1];
    
    for (const word of words) {
        if (word[0] !== lastChar) {
            return false;
        }
        lastChar = word[word.length - 1];
    }
    
    return true;
};