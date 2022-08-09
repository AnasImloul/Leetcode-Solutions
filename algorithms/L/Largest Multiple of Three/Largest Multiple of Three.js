/**
 * @param {number[]} digits
 * @return {string}
 */
var largestMultipleOfThree = function(digits) {
    // highest digit first
    digits.sort((l, r) => r - l);
    
    // what is the remainder of the total sum?
    const sumRemainder = digits.reduce((a, c) => a + c, 0) % 3;
    
    if (sumRemainder) {
        let targetIndex = 0, i = digits.length - 1;
        
        // try to find what is the smallest number that can be removed
        for (; i >= 0; i--) {
            if ((digits[i] - sumRemainder) % 3 === 0) {
                targetIndex = i;
                break;
            }
        }

        if (i < 0) {
            // iterated the whole loop, couldn't find a single number to remove
            // remove everything but multiples of 3
            digits = digits.filter(v => v % 3 === 0);
        } else {
            digits.splice(targetIndex, 1);
        }
    }
    
    return (digits[0] === 0) ? '0' : digits.join('');
};
