// Runtime: 42 ms (Top 95.45%) | Memory: 42.50 MB (Top 14.77%)

/**
 * @param {number} n
 * @return {number[]}
 */
var getNoZeroIntegers = function(n) {
    for(let indexI=1; indexI<n; indexI++){
        const firstNum=indexI;
        const secondNum = n-indexI;

        if(secondNum.toString().match(/[0]/g) || firstNum.toString().match(/[0]/g)) continue;

        return [firstNum, secondNum]
    }
};
