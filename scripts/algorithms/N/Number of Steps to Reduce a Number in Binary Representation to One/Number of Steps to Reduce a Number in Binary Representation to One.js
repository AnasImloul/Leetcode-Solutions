// Runtime: 106 ms (Top 32.20%) | Memory: 42.5 MB (Top 52.54%)
var numSteps = function(s) {
    let res = 0;
    s = s.split("");
    while(s.length>1){
        if(s[s.length-1]==="0") s.pop();
        else plusone(s);
        res++;
    }
    return res;
};
var plusone = function(p) {
    p.unshift("0");
    let i = p.length-1;
    p[i] = 1+(+p[i]);
    while(p[i]===2){
        p[i-1] = 1+(+p[i-1]);
        i--;
        p[i+1] = "0";
    }
    if(p[0]==="0") p.shift();
    return p;
};