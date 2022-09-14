// Runtime: 409 ms (Top 44.03%) | Memory: 65.6 MB (Top 60.70%)
var wordSubsets = function(words1, words2) {
    this.count = Array(26).fill(0);
    let tmp = Array(26).fill(0);
    for(let b of words2){
        tmp = counter(b);
        for(let i=0; i<26; i++)
            count[i] = Math.max(count[i], tmp[i]);
    }
    let list = []
    for(let a of words1)
        if(isSub(counter(a)))
            list.push(a);
    return list;
};

function isSub(tmp){
    for(let i=0; i<26; i++)
        if(tmp[i] < this.count[i])
            return false;
    return true;
};

function counter(s){
    let tmp = Array(26).fill(0);
    for(let c of s)
        tmp[c.charCodeAt() - 97]++;
    return tmp;
};