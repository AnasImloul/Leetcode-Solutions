// Runtime: 86 ms (Top 69.22%) | Memory: 41.9 MB (Top 44.06%)
/**
 * @param {number} n
 * @return {number}
 */
 // Recursion and memomization approach
var fib = function(n,cache ={}) {
    if (n <= 0) return 0
    if(n in cache) {
        return cache[n]
    }
    if(n == 1 || n == 2) {
        return 1;
    }
    cache[n] = fib(n-1,cache) + fib(n-2,cache)
    return cache[n]
};
//Tabulation approach
var fib = function(n) {
    const table = new Array(n + 1).fill(0);
    table[1] = 1;
    for(let i = 0;i<=n;i++) {
            table[i+1] += table[i];
            table[i+2] += table[i];
    }
    return table[n]
};