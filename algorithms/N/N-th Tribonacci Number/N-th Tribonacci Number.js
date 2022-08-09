// Recursive and Memoiztion approach
var tribonacci = function(n, cache = {}) {
    if(n in cache) return cache[n]

    //Start of Base Cases
    if(n == 0) return 0
    if (n == 1 || n == 2) return 1;
    // End Of Base Cases
    
    // Caching the result
    cache[n] = tribonacci(n - 1, cache) + tribonacci(n - 2, cache) + tribonacci(n - 3, cache);
    
    return cache[n]; 
};

// Tabulation Approach
var tribonacci = function(n) {
    // Create the Table;
    const table = Array(n + 1).fill(0);
    table[1] = 1;
    for(let i =0;i<=n;i++){
        //Iterate over the table and increase the values respectively
        table[i+1] += table[i]
        table[i+2] += table[i]
        table[i+3] += table[i]
    }
    return table[n]
};
