// Runtime: 667 ms (Top 81.08%) | Memory: 48.8 MB (Top 62.16%)
var beautySum = function(s) {
    const len = s.length;

    let ans = 0;
    const freq = new Array(26).fill(0);

    for(let i = 0; i < len; i++) {
        freq[s[i].charCodeAt(0) - 'a'.charCodeAt(0)]++;
        for(let j = i + 1; j < len; j++) {
            freq[s[j].charCodeAt(0) - 'a'.charCodeAt(0)]++;
            ans += minMaxDiff(freq);
        }
        freq.fill(0);
    }

    function minMaxDiff(freq) {
        freq = freq.filter(f => f != 0);
        return Math.max(...freq) - Math.min(...freq);
    }

    return ans;
};