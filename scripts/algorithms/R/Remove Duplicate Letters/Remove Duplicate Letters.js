// Runtime: 56 ms (Top 86.81%) | Memory: 51.10 MB (Top 5.49%)

/**
 * @param {string} s
 * @return {string}
 */
var removeDuplicateLetters = function(s) {
    const lastOccurrence = {};
    for (let i = 0; i < s.length; i++) {
        lastOccurrence[s[i]] = i;
    }

    const stack = [];
    const visited = new Set();

    for (let i = 0; i < s.length; i++) {
        if (visited.has(s[i])) {
            continue;
        }

        while (
            stack.length > 0 &&
            s[i] < stack[stack.length - 1] &&
            i < lastOccurrence[stack[stack.length - 1]]
        ) {
            visited.delete(stack.pop());
        }

        visited.add(s[i]);
        stack.push(s[i]);
    }

    return stack.join('');    
};
