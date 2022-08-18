// Runtime: 87 ms (Top 55.41%) | Memory: 42 MB (Top 85.35%)

var hIndex = function(citations) {
    citations.sort((a,b)=>b-a)
    let i=0
    while(citations[i]>i) i++

    return i
};