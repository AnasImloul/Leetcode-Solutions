// Runtime: 2445 ms (Top 18.75%) | Memory: 52 MB (Top 18.75%)
var lastSubstring = function(s) {
    let res = 0;
    for(let i = 1; i < s.length; i++){
        if(s.slice(i) > s.slice(res)) res = i;
    };
    return s.slice(res);
};