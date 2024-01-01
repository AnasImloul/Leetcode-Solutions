// Runtime: 57 ms (Top 47.06%) | Memory: 42.40 MB (Top 5.88%)

/**
 * @param {number} num
 * @param {number} k
 * @return {number}
 */
var minimumNumbers = function(num, k) {
    if (num === 0) return 0
    if (num === k) return 1
    if (k === 0) return num % 10 !== 0 ? -1 : 1
    
    let x = Math.floor(num / k)
    
    while (x >= 0) {
        if ((num - 10 * x) > 0 && (num - 10 * x) % k === 0) {
            return (num - 10 * x) / k
        }
        x--
    }
    
    return -1
};
