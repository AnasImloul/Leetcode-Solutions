// Runtime: 36 ms (Top 99.72%) | Memory: 49.00 MB (Top 6.7%)

/**
 * @param {number} num
 * @return {number}
 */
var countDigits = function(num) {
    let count = 0
    let str = String(num).split('')
    for(let i = 0; i < str.length; i++) {
        if(num % str[i] == 0) count++
    }
    return count
};
