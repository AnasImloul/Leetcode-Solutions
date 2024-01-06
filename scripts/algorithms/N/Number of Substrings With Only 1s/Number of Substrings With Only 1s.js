// Runtime: 58 ms (Top 68.6%) | Memory: 45.00 MB (Top 50.0%)

var numSub = function(s) {
    return s.split("0").map(a=>a.length*(a.length+1)/2).reduce((a,b)=>a+b,0)  % 1000000007;
};
