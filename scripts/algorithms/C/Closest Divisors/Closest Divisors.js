// Runtime: 145 ms (Top 27.27%) | Memory: 42.3 MB (Top 59.09%)
/**
 * @param {number} num
 * @return {number[]}
 */
var closestDivisors = function(num) {
    const n1 = num + 1;
    const n2 = num + 2;

    let minDiff = Infinity;
    let result = [];
    for(let i = Math.floor(Math.sqrt(n2)); i >= 1; i--) {
        if(n1 % i === 0) {
            const diff = Math.abs(i - (n1 / i));
            if(diff < minDiff) {
                minDiff = diff;
                result = [i, n1 / i]
            }
        }

        if(n2 % i === 0) {
            const diff = Math.abs(i - (n2 / i));
            if(diff < minDiff) {
                minDiff = diff;
                result = [i, n2 / i]
            }
        }
    }

    return result;
};