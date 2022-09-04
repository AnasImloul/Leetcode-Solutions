// Runtime: 79 ms (Top 80.89%) | Memory: 42.4 MB (Top 62.06%)
var hammingWeight = function(n) {
    let count = 0, i = 0;
    while(n > 0) {
        i = 0;
        while(n >= Math.pow(2,i)) {
            i++;
        }
        count++;
        n -= Math.pow(2,i-1);
    }
    return count;
};