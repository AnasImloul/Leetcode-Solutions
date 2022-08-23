// Runtime: 119 ms (Top 57.14%) | Memory: 49 MB (Top 61.90%)
var largestMerge = function(word1, word2) {
    let ans = '';
    let w1 = 0, w2 = 0;

    while(w1 < word1.length && w2 < word2.length) {
        if(word1[w1] > word2[w2]) ans += word1[w1++];
        else if(word2[w2] > word1[w1]) ans += word2[w2++];
        else {
            const rest1 = word1.slice(w1);
            const rest2 = word2.slice(w2);

            if(rest1 > rest2) ans += word1[w1++];
            else ans += word2[w2++];
        }
    }
    ans += word1.slice(w1);
    ans += word2.slice(w2);
    return ans;
};