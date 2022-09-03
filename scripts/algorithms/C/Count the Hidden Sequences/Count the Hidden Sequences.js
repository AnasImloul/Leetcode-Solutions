// Runtime: 212 ms (Top 12.50%) | Memory: 69.6 MB (Top 12.50%)
var numberOfArrays = function(differences, lower, upper) {
    let temp = 0;
    let res = 0;
    let n = lower;

    for (let i = 0; i < differences.length; i++) {
        temp += differences[i];
        differences[i] = temp;
    }

    const min = Math.min(...differences);
    const max = Math.max(...differences);

    while (n <= upper) {
        if (n + min >= lower && n + max <= upper) res++;
        n++;
    }
    return res;
};