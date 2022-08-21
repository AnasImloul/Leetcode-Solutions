// Runtime: 101 ms (Top 40.00%) | Memory: 43.2 MB (Top 25.45%)

var consecutiveNumbersSum = function(n) {
    let count = 1;
    for (let numberOfTerms = 2; numberOfTerms < Math.sqrt(2*n) + 1; numberOfTerms++) {
        let startNumber = (n - numberOfTerms * (numberOfTerms - 1) / 2) / numberOfTerms;
        if (Number.isInteger(startNumber) && startNumber !== 0) {
            count++;
        }
    }
    return count;
};