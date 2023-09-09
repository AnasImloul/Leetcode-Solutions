// Runtime: 54 ms (Top 83.3%) | Memory: 45.05 MB (Top 16.6%)

var getLastMoment = function(n, left, right) {
    const maxLeft = Math.max(...left);
    const minRight = Math.min(...right);

    return Math.max(n - minRight, maxLeft);
};