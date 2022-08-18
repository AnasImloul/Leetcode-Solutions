// Runtime: 95 ms (Top 53.17%) | Memory: 41.8 MB (Top 94.44%)

var isLongPressedName = function(name, typed) {
    let i = 0;
    let j = 0;
    while (j < typed.length) {
        if (i < name.length && name[i] === typed[j]) i++;
        else if (typed[j] !== typed[j - 1]) return false; // this needs when name is traversed but there is tail of characters in typed
        j++; // Base case. keep going through typed anyway hitting first condition from time to time: (i < name.length && name[i] === typed[j])
    }

    return i === name.length;
};