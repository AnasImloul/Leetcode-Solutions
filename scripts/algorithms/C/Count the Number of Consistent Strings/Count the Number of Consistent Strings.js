// Runtime: 78 ms (Top 91.24%) | Memory: 51.20 MB (Top 63.23%)

/**
 * @param {string} allowed
 * @param {string[]} words
 * @return {number}
 */
var countConsistentStrings = function(allowed, words) {
    const hashmap = new Map();
    let output = 0;

    for (let i = 0; i < allowed.length; i++) {
        hashmap.set(allowed[i], 1);
    }

    for (let i = 0; i < words.length; i++) {
        const word = words[i];
        output++;
        for (let j = 0; j < word.length; j++) {
            if (!hashmap.has(word[j])) {
                output--;
                break;
            }
        }
    }

    return output;
};
