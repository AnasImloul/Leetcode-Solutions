// Runtime: 52 ms (Top 89.65%) | Memory: 42.70 MB (Top 31.03%)

var judgeSquareSum = function(c) {
    if (c === 0) {
        return true
    }
    for (let a = 0; a*a < c; a++) {
        let b = Math.sqrt(parseFloat(c-a*a));
        if (b - Math.round(b) === 0) {
            return true;
        }
    }
        return false
};

