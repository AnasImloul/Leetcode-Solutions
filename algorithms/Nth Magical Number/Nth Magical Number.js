/**
 * @param {number} n
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var nthMagicalNumber = function(n, a, b) {
    const gcd = (a1,b1)=>{
        if(b1===0) return a1;
        return gcd(b1,a1%b1)
    }
    const modulo = 1000000007;
    let low = 0;
    let high = 10e17;
    let lcmAB = Math.floor((a*b)/gcd(a,b));
    
    while(low<high){
        let mid = Math.floor((low+high)/2);
        let ans = Math.floor(mid/a)+Math.floor(mid/b)-Math.floor(mid/lcmAB);
        if(ans<n){
            low = mid + 1;
        }else{
            high = mid;
        }
    }
    return high%modulo;
};
