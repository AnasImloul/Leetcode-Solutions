// Runtime: 439 ms (Top 90.04%) | Memory: 82.1 MB (Top 91.87%)
function makeSieve(n) {
    let arr = new Array(n+1)
    arr[0] = false;
    arr[1] = false;
    arr.fill(true,2,arr.length);

    for( let i = 2; i*i<n; i++) {
        if(arr[i] === true) {
            for( let j = i*i ; j<=n ;j+=i){
                arr[j] = false;
            }
        }
    }

    let count = 0;

    for(let i = 0; i<n;i++) {
        if(arr[i] == true) {
            count++;
        }
    }
    return count;
}

var countPrimes = function(n) {
    let numberOfPrimes = makeSieve(n)
    return numberOfPrimes;
};