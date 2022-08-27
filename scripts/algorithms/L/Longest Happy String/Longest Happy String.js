// Runtime: 112 ms (Top 17.70%) | Memory: 41.8 MB (Top 94.69%)
var longestDiverseString = function(a, b, c) {
    let str = '', aCount = 0, bCount = 0, cCount = 0;
    let len = a + b + c;
    for(let i = 0; i < len; i++) {
        if (a >= b && a >= c && aCount != 2 || bCount == 2 && a > 0 || cCount == 2 && a > 0) {
            adjustCounts('a', aCount+1, 0, 0);
            a--;
        } else if (b >= a && b >= c && bCount != 2 || aCount == 2 && b > 0 || cCount == 2 && b > 0) {
            adjustCounts('b', 0, bCount+1, 0);
            b--;
        } else if (c >= a && c >= b && cCount != 2 || bCount == 2 && c > 0|| aCount == 2 && c > 0) {
            adjustCounts('c', 0, 0 , cCount+1);
            c--;
        }
    }

    function adjustCounts(letter, newA, newB, newC){
        aCount = newA;
        bCount = newB;
        cCount = newC;
        str += letter;
    }

    return str;
};