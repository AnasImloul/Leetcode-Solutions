/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function(word1, word2) {
    let length = Math.max(word1.length, word2.length), s = '';
    for(let i = 0; i < length; i++){
        s+= word1[i] || '';
        s+= word2[i] || '';
    }
    return s;
};