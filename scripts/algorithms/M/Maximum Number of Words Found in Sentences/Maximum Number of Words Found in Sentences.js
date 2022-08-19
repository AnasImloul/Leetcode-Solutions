// Runtime: 65 ms (Top 95.45%) | Memory: 43.6 MB (Top 89.35%)

/**
 * @param {string[]} sentences
 * @return {number}
 */
var mostWordsFound = function(sentences) {
    let max = 0;
    let temp = 0;
    for (let i = 0; i < sentences.length; i++) {
        temp = sentences[i].split(" ").length;
        if (temp > max) {
            max = temp;
        }
    }

    return max;
};