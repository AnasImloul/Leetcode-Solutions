var removeDuplicateLetters = function(s) {
    let sset = [...new Set(s)]
    if(Math.min(sset) == sset[0]) return [...sset].join('');
    else {
        sset.sort();
        return [...sset].join('');
    }
};
