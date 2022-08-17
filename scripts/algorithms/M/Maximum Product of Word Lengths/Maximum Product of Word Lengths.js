/**
 * @param {string[]} words
 * @return {number}
 */
var maxProduct = function(words) {
    words.sort((a, b) => b.length - a.length);
    
    const m = new Map();
    for(let word of words) {
        if(m.has(word)) continue;
        const alpha = new Array(26).fill(0);
        for(let w of word) {
            let idx = w.charCodeAt(0) - 'a'.charCodeAt(0);
            alpha[idx] = 1;
        }
        m.set(word, parseInt(alpha.join(''), 2));
    }
    
    const hasCommonLetters = (a, b) => {
        const sb = m.get(b);
        const sa = m.get(a);
        return (sa & sb) != 0;
    }
    let ans = 0, len = words.length;
    for(let i = 0; i < len; i++) {
        for(let j = i + 1; j < len; j++) {
            if(!hasCommonLetters(words[i], words[j])) {
                ans = Math.max(ans, words[i].length * words[j].length);
            }
        }
    }
    return ans;
};
