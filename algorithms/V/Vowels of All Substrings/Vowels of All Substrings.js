var countVowels = function(word) {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    let total = 0;
    let count = 0;
    for (let i = 0; i < word.length; i++) {
        if (vowels.has(word[i])) {
            count += i + 1;
        }
        total += count;
    }
    return total;
};
