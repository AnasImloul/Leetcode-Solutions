// Runtime: 40 ms (Top 97.32%) | Memory: 41.70 MB (Top 60.47%)

var climbStairs = function(n) {
    if (n < 4) return n;
    let fib = [1, 1];
    for (let i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
};
