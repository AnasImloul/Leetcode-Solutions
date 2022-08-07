/**
 * @param {string} s
 * @param {string[]} dictionary
 * @return {string}
 */
var findLongestWord = function(s, dictionary) {
    const getLen = (s1, s2) => {
        let i = 0, j = 0;
        while(i < s1.length && j < s2.length) {
            if(s1[i] == s2[j]) { i++, j++; }
            else i++;
        }
        if(j != s2.length) return 0;
        return s2.length;
    }
    let ans = '', ml = 0;
    for(let word of dictionary) {
        const len = getLen(s, word);
        if(len > ml) {
            ans = word;
            ml = len;
        }
        else if(len == ml && ans > word) {
            ans = word;
        }
    }
    return ans;
};
