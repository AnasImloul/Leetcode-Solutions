// Runtime: 115 ms (Top 46.43%) | Memory: 49.20 MB (Top 30.36%)

var numSmallerByFrequency = function(queries, words) {
    const wordsF = words.map(word => f(word));
    return queries.map(str => f(str))
        .map(strF => wordsF.reduce((count, wordF) => strF<wordF? count+1:count,0))
};

function f(str){
    return str.split("").sort().reduce((sum, curr,i,arr) => curr === arr[0] ? sum+1: sum,0);
}
