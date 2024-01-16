// Runtime: 962 ms (Top 50.0%) | Memory: 48.20 MB (Top 25.0%)

/**
 * @param {string} text
 * @return {number}
 */
var distinctEchoSubstrings = function(text) {
    const store = new Set();
    for (let i = 0; i < text.length; i++) {
        for (let j = i + 1; j < text.length; j++) {
            const left = text.substring(i,j);
			const right = text.substring(j, j + j - i);
            if (left === right) store.add(left);
        }
    }
    return store.size;
};
