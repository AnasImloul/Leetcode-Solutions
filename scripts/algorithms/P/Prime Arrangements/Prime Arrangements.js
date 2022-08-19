// Runtime: 80 ms (Top 70.37%) | Memory: 46.7 MB (Top 14.81%)

/**
 * @param {number} n
 * @return {number}
 */

var findNoOfPrimes = function(n){
    let isPrime = new Array(n+1).fill(true);

    let count =0;

    for(let i=2; i<n;i++){
        for(let j=i;j<=n;j++){
            isPrime[j*i]= false;
        }
    }

    isPrime.forEach(prime=> {
        if(prime){
            count++
        }
    })

    return count-2;
}

var factorial = function(num){
    let modulo = Math.pow(10,9) +7;

    if(num<=0)
        return 1;

    return (BigInt(num) * BigInt(factorial(num-1)))%BigInt(modulo) ;
}

var numPrimeArrangements = function(n) {

    let modulo = BigInt(Math.pow(10,9) +7);

    let count = findNoOfPrimes(n);

    let factorialPrime = factorial(count);

    let factorialComposite = factorial(n-count);

    return (BigInt(factorialPrime)*BigInt(factorialComposite))% (modulo);
};