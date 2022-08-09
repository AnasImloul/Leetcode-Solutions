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
