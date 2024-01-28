// Runtime: 44 ms (Top 85.71%) | Memory: 49.60 MB (Top 14.29%)

var minNonZeroProduct = function(p) {
    p = BigInt(p);
    
    const MOD = BigInt(1e9 + 7);
    const first = ((1n << p) - 1n);
    
   const half = first / 2n;
    
    const second = powMOD(first - 1n, half); 
    
    return (first * second) % MOD;
    
    function powMOD(num, exp) {
        if (exp === 0n) return 1n; 
        
        const tmp = powMOD(num, exp >> 1n);
        
        let res = (tmp * tmp) % MOD;
        
        if (exp % 2n) res = (res * num) % MOD;
        
        return res;
    }
};  
