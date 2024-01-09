// Runtime: 46 ms (Top 82.9%) | Memory: 41.90 MB (Top 24.93%)

var countSegments = function(s) {
    let count = 0;
    
    for (let i = 0; i < s.length; i++) {
        // Check if the current character is a non-space character and the previous character is a space or the start of the string
        if (s[i] !== ' ' && (i === 0 || s[i - 1] === ' ')) {
        count++;
        }
    }
    
    return count;
}
