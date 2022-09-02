// Runtime: 102 ms (Top 97.93%) | Memory: 45.7 MB (Top 99.22%)
var addToArrayForm = function(num, k) {
    const length = num.length;
    let digit = 0, index = length-1;
    while(k > 0 || digit > 0) {
        if(index >= 0) {
            digit = digit + num[index] + k%10;
            num[index] = digit%10;
        }
        else {
            digit = digit + k%10;
            num.unshift(digit%10);
        }
        digit = digit > 9 ? 1 : 0;
        k = parseInt(k/10);
        index--;
    }
    if(digit) num.unshift(digit);
    return num;
};