// Runtime: 111 ms (Top 65.71%) | Memory: 41.8 MB (Top 92.86%)
var countTriples = function(n) {
    let count = 0;
    for (let i=1; i < n; i++) {
        for (let j=1; j < n; j++) {
            let root = Math.sqrt(j*j + i*i)
            if (Number.isInteger(root) && root <= n) {
                count++
            }
        }
    }

    return count
};