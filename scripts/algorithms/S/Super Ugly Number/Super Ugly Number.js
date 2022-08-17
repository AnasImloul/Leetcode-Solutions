var nthSuperUglyNumber = function(n, primes) {
    const table = Array(primes.length).fill(0);
    const res = Array(n);
    res[0] = 1;
    for(let j=1;j<n;j++){
        let curr = Infinity;
        for (let i=0;i< table.length; i++) {
            curr = Math.min(curr, res[table[i]]*primes[i]);
        }
        for (let i=0;i< table.length; i++) {
            if (curr === res[table[i]]*primes[i]) table[i]++;
        }
        res[j] = curr;
    }
    return res[n-1];
};
