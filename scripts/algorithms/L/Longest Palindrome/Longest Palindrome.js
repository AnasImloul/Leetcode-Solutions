// Runtime: 112 ms (Top 32.41%) | Memory: 43.7 MB (Top 65.09%)
var longestPalindrome = function(s) {
    const hashMap = {};
    let ouput = 0;
    let hashOdd = false;

    for (let i = 0; i < s.length; i++) {
        if (!hashMap[s[i]]) {
            hashMap[s[i]] = 0;
        }
        hashMap[s[i]] += 1;
    }

    Object.values(hashMap)?.forEach(character => {
        ouput += character%2 ? character - 1 : character;
        if (character%2 && !hashOdd) {
            hashOdd = true;
        }
    });

    return ouput + (hashOdd ? 1 : 0);
};