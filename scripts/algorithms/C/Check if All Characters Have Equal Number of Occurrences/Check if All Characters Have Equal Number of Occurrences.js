// Runtime: 116 ms (Top 33.13%) | Memory: 44.9 MB (Top 21.58%)
var areOccurrencesEqual = function(s) {
    var freq = {}
    for (let c of s) freq[c] = (freq[c] || 0) + 1
    var val = freq[s[0]]
    for (let c in freq) if (freq[c] && freq[c] != val) return false;
    return true;
};