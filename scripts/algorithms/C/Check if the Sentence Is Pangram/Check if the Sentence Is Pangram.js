// Runtime: 66 ms (Top 92.66%) | Memory: 42.6 MB (Top 67.15%)
var checkIfPangram = function(sentence) {
    return new Set(sentence.split("")).size == 26;
};