var reversePrefix = function(word, ch) {
    return word.indexOf(ch) !== -1 ? word.split("").slice(0, word.indexOf(ch) + 1).reverse().join("") + word.slice(word.indexOf(ch) + 1) : word;
};
