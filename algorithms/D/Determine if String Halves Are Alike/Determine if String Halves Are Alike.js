var halvesAreAlike = function(s) {
    let isVowel = ["a","e","i","o","u","A","E","I","O","U"];
    let count = 0;
    for (let i = 0; i < s.length / 2; i++) {
        if (isVowel.indexOf(s[i]) !== -1) {
            count++;
        }
    }
    for (let i = s.length / 2; i < s.length; i++) {
        if (isVowel.indexOf(s[i]) !== -1) {
            count--;
        }
    }
    return count === 0;
};
