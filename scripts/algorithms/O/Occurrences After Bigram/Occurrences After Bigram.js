// Runtime: 92 ms (Top 39.29%) | Memory: 41.6 MB (Top 81.43%)
var findOcurrences = function(text, first, second) {
    let result = [];
    let txt = text.split(' ');
    for(let i = 0; i<txt.length - 2; i++) {
        if(txt[i] === first && txt[i+1] === second) result.push(txt[i+2]);
    }
    return result;
};