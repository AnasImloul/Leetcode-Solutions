// Runtime: 57 ms (Top 42.11%) | Memory: 42.10 MB (Top 39.47%)

/**
 * @param {string} pattern
 * @return {string}
 */
var smallestNumber = function(pattern) {
    const ans = [];
    let stack = [];
    
    for (let i = 0; i <= pattern.length; i++) {
        stack.push(i + 1);
        if (pattern[i] === 'I' || i === pattern.length) {
            ans.push(...stack.reverse());
            stack = [];
        }
    }
    
    return ans.join('');
};
