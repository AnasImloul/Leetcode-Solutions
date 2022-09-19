// Runtime: 157 ms (Top 28.08%) | Memory: 44.7 MB (Top 69.70%)
var canConstruct = function(ransomNote, magazine) {
    map = {};
    for(let i of magazine){
        map[i] = (map[i] || 0) + 1;
    }
    for(let i of ransomNote){
        if(!map[i]){
            return false
        }
        map[i]--;
    }
    return true
};