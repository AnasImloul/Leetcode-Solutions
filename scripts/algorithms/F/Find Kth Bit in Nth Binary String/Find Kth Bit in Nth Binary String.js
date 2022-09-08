// Runtime: 1452 ms (Top 22.22%) | Memory: 112 MB (Top 33.33%)
var findKthBit = function(n, k) {
    return recursivelyGenerate(n-1)[k-1];
}

function recursivelyGenerate(bitLength, memo=new Array(bitLength+1)){
    if(bitLength===0) return "0";
    if(memo[bitLength]) return memo[bitLength];
    const save = recursivelyGenerate(bitLength-1);
    memo[bitLength] = save + '1' + reverseInvert(save);
    return memo[bitLength];
}

function reverseInvert(s){
    return s.split("").map(a=>a==='0'?'1':'0').reverse().join("");
}