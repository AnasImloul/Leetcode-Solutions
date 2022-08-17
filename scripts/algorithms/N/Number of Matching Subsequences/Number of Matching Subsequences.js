var numMatchingSubseq = function(s, words) {
    let subsequence = false;
    let count = 0;
    let prevIdx, idx 
    for(const word of words) {
        prevIdx = -1;
        idx = -1;
        subsequence = true;
        for(let i = 0; i < word.length; i++) {
            idx = s.indexOf(word[i], idx + 1);
            if(idx > prevIdx) {
                prevIdx = idx;
            } else {
                subsequence = false;
                break;
            }
        }
        if(subsequence) count++;
    }
    return count;
};
