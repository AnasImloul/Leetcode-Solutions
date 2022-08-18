// Runtime: 58 ms (Top 97.37%) | Memory: 42.2 MB (Top 43.42%)

var findNthDigit = function(n) {
    var len = 1;
    var range = 9;
    var base = 1;
    while(n>len*range)
    {
        n -= len *range;
        range *= 10;
        base *= 10;
        len++;
    }
    // [100, 101, 102,...]
    // 100 should have offset 0, use (n-1) to make the counting index from 0-based.
    var num = base + Math.floor((n-1)/len);
    var s = num.toString();
    return parseInt(s[(n-1)%len]);
};