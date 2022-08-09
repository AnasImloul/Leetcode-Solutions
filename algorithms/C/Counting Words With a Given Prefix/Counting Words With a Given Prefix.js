var prefixCount = function(words, pref) {
    return words.filter(word => word.slice(0, pref.length) === pref).length;
};
