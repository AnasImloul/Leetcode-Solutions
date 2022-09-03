// Runtime: 91 ms (Top 100.00%) | Memory: 47.1 MB (Top 69.23%)
var numWays = function(s) {
    let one = 0;
    let list = [];
    for(let i = 0; i < s.length; i++){
        if(s[i]==="1") one++, list.push(i);
    }
    if(one%3!==0) return 0;
    if(one===0) return ((s.length-1)*(s.length-2)/2) % 1000000007;
    one/=3;
    return ((list[one]-list[one-1])*(list[2*one]-list[2*one-1])) % 1000000007;
};