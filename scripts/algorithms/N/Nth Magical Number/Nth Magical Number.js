// Runtime: 46 ms (Top 97.37%) | Memory: 42.00 MB (Top 86.84%)

/**
 * @param {number} N
 * @param {number} A
 * @param {number} B
 * @return {number}
 */
var nthMagicalNumber = function(N, A, B) {
    var temp;
    if(B > A){
        temp = A;
        A = B;
        B = temp;
    }
    //A is bigger
    
    var shareFreq = ((A+B)/GCD(A,B))-1;
    var numShares = Math.floor(N/shareFreq);
    var superN = N + numShares;
    
    //X+Y = superN
    
    var X = Math.ceil(superN*B/(A+B));
    var Y = Math.ceil(superN-(superN*B/(A+B)));
    
    var mod = (10**9)+7;
    
    if(X*A <= Y*B)return (X*A)%mod;
    else return (Y*B)%mod;
};

var GCD = function(x,y){
    while(y!=0){
        var t = y;
        y = x % y;
        x = t;
    }
    return x;
}
