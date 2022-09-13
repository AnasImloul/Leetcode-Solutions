// Runtime: 261 ms (Top 34.83%) | Memory: 49.1 MB (Top 40.45%)
var rangeBitwiseAnd = function(left, right) {
    const a = left.toString(2);
    const b = right.toString(2);

    if (a.length !== b.length) {
        return 0;
    }

    let match = 0;

    for (let i = 0; i < a.length; i++) {
        if (a[i] !== b[i]) {
            break;
        }

        match++;
    }

    return parseInt(b.substring(0, match).padEnd(b.length, '0'), 2);
};