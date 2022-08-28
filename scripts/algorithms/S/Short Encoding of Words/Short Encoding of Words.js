// Runtime: 157 ms (Top 60.61%) | Memory: 61.9 MB (Top 9.09%)
/**
 * @param {string[]} words
 * @return {number}
 */
class Trie {
    constructor(letter) {
        this.letter = letter;
        this.children = new Map();
        this.isWord = false;
    }
}

var minimumLengthEncoding = function(words) {
    let minEncodingLength = 0;
    const sortedWords = words.sort((a, b) => a.length - b.length);

    const buildTrie = (root, word, index) => {
        // This means we reached to the end of word, so mark it as a word and compute encoding length
        if (index < 0) {
            minEncodingLength += word.length + 1;
            root.isWord = true;
            return;
        }

        const character = word[index];
        // If we do not have a char in children, create a node and add it under root
        if (!root.children.has(character)) {
            const node = new Trie(character);
            root.children.set(character, node);
            buildTrie(node, word, index - 1);
            return;
        }

        const node = root.children.get(character);
        // Remove the common suffix length considered before since it would be covered as a part of current word traversal
        if (node.isWord) {
            node.isWord = false;
            minEncodingLength -= word.length - index + 1;
        }

        buildTrie(node, word, index - 1);
    };

    const root = new Trie();
    for (const word of sortedWords) {
        buildTrie(root, word, word.length - 1);
    }

    return minEncodingLength;
};