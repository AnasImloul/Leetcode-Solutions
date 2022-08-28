// Runtime: 135 ms (Top 60.53%) | Memory: 45.4 MB (Top 55.95%)
const getCharIdx = (c) => c.charCodeAt(0) - 'a'.charCodeAt(0);
const isEqual = (a, b) => a.every((v, i) => v == b[i]);

var checkInclusion = function(s1, s2) {
    const occS1 = new Array(26).fill(0);
    const occS2 = new Array(26).fill(0);

    const s1Len = s1.length, s2Len = s2.length;

    if(s1Len > s2Len) return false;

    let l = 0, r = 0;
    for(; r < s1Len ; r++) {
        occS1[getCharIdx(s1[r])]++;
        occS2[getCharIdx(s2[r])]++;
    }

    if(isEqual(occS1, occS2)) {
        return true;
    }

    for(; r < s2Len; r++) {
        occS2[getCharIdx(s2[r])]++;
        occS2[getCharIdx(s2[l++])]--;

        if(isEqual(occS1, occS2)) return true;
    }

    return false;
};