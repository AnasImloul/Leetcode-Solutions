// Runtime: 1902 ms (Top 50.75%) | Memory: 44.5 MB (Top 91.32%)
const buildTrie = (words) => {
    const trie = {};
    const addToTrie = (word, index = 0, node = trie) => {
        const char = word[index];
        if(!node[char]) {
            node[char] = {};
        }

        if(index === word.length - 1) {
            node[char].word = word;
            return word;
        }

        return addToTrie(word, index + 1, node[char]);
    };

    words.map((word) => addToTrie(word));
    return trie;
};

const dfs = (i, j, board, node, wordsFound = []) => {
    if(i < 0 || i >= board.length) return wordsFound;
    if(j < 0 || j >= board[board.length - 1].length) return wordsFound;

    const char = board[i][j];
    if(char === '#') return wordsFound;

    if(node[char]) {
        if(node[char].word) {
            wordsFound.push(node[char].word);
            node[char].word = null;
        }

        board[i][j] = '#';
        dfs(i + 1, j, board, node[char], wordsFound);
        dfs(i, j + 1, board, node[char], wordsFound);
        dfs(i - 1, j, board, node[char], wordsFound);
        dfs(i, j - 1, board, node[char], wordsFound);
        board[i][j] = char;
    }

    return wordsFound;
};

var findWords = function(board, words) {
    const m = board.length;
    const n = board[m - 1].length;
    const trie = buildTrie(words);

    let result = [];
    for(let i = 0; i < m; i += 1) {
        for(let j = 0; j < n; j += 1) {
            result = result.concat(dfs(i, j, board, trie));
        }
    }
    return result;
};