// Runtime: 96 ms (Top 66.73%) | Memory: 43.9 MB (Top 16.57%)
var isPowerOfFour = function(n) {
    if(n==1){
        return true
    }
    let a=1;
    for(let i=2;i<=30;i++){
        a=a*4
        if(a===n){
            return true
        }
    }
    return false
};