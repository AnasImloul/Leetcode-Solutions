// Runtime: 5040 ms (Top 9.23%) | Memory: 41.7 MB (Top 89.23%)
var minMoves = function(target, maxDoubles) {
    if (maxDoubles === 0) return target - 1;
    let count = 0;

    while (target > 1) {
        if (target % 2 === 0 && maxDoubles > 0) {
            target /= 2;
            maxDoubles--;
        } else {
            target--;
        }

        count++;
    }

    return count;
};