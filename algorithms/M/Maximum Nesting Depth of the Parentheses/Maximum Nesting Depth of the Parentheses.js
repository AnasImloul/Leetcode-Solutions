var maxDepth = function(s) {
    let maxCount = 0, count = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            maxCount = Math.max(maxCount, ++count);
        } else if (s[i] === ')') {
            count--;
        }
    }
    return maxCount;
};
