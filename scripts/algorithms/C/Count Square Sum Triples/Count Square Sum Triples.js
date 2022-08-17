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
