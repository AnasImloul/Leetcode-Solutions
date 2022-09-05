// Runtime: 93 ms (Top 52.17%) | Memory: 42.1 MB (Top 65.22%)
var sumOfThree = function(num) {
    return (num % 3 === 0) ? [num / 3 - 1, num / 3, num / 3 + 1] : [];
};