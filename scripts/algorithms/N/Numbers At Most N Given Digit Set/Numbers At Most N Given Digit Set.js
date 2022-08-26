// Runtime: 68 ms (Top 95.45%) | Memory: 41.6 MB (Top 100.00%)
var atMostNGivenDigitSet = function(digits, n) {
    const asString = ""+ n;
    let smaller = 0;
    let prev = 1;
    for (let i = asString.length - 1; i >= 0; --i) {
        const L = asString.length - 1 - i;
        const num = +asString[i];
        let equal = 0;
        let less = 0;
        for (let digit of digits) {
            if (digit == num) {
                equal = 1;
            }
            if (digit > num) {
                break;
            }
            if (digit < num) {
                less++;
            }
        }
        prev = (less * Math.pow(digits.length, L)) + equal * prev;
        if (L < asString.length - 1) {
            smaller += Math.pow(digits.length, L + 1);
        }
    }
    return smaller + prev;
};