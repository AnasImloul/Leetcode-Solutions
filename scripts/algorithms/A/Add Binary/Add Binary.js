// Runtime: 52 ms (Top 82.96%) | Memory: 41.90 MB (Top 95.02%)

var addBinary = function(a, b) {
    return (BigInt("0b"+a) + BigInt("0b"+b)).toString(2);
}
