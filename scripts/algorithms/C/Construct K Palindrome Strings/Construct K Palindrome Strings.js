// Runtime: 160 ms (Top 49.09%) | Memory: 45.8 MB (Top 67.27%)
var canConstruct = function(s, k) {
    if(s.length < k) return false;
    // all even all even
    // all even max k odd
    const freq = {};
    for(let c of s) {
        freq[c] = (freq[c] || 0) + 1;
    }

    let oddCount = 0;
    const freqOfNums = Object.values(freq);
    for(let cnt of freqOfNums) {
        if(cnt & 1) oddCount++;
    }

    return oddCount <= k;
};