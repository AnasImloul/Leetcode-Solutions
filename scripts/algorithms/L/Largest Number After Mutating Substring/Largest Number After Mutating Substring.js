// Runtime: 263 ms (Top 13.33%) | Memory: 66.8 MB (Top 46.67%)
var maximumNumber = function(num, change) {
    const digits = num.split("");

    let started = false;

    for (let i = 0; i < digits.length; ++i) {
        const origDig = digits[i];
        const changeDig = change[origDig];

        if (changeDig > origDig) {
            started = true;
            digits[i] = changeDig;
        }
        else if (changeDig < origDig && started) {
            break;
        }
    }

    return digits.join("");
};