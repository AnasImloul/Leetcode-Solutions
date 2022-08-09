var checkIfPangram = function(sentence) {
    return new Set(sentence.split("")).size == 26;
};
