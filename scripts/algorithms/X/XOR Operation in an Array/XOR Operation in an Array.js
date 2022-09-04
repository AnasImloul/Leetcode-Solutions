// Runtime: 109 ms (Top 13.69%) | Memory: 42.1 MB (Top 30.04%)
var xorOperation = function(n, start) {
    let arr = []
    for(let i=0; i<n; i++){
        arr.push(start+2*i)
    }
    return arr.reduce((a,c)=> a^c)
};