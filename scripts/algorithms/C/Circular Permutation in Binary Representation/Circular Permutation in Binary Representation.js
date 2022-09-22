// Runtime: 152 ms (Top 85.71%) | Memory: 56.7 MB (Top 28.57%)
var circularPermutation = function(n, start) {
    const grayCodes = [];

    let startIdx = -1;

    for (let i = 0; i <= 2**n - 1; i++) {
        grayCodes[i] = i ^ (i >> 1);

        if (grayCodes[i] == start) startIdx = i;
    }

    const res = [];

    for (let i = 0; i <= 2**n - 1; i++) {
        res[i] = grayCodes[startIdx];

        startIdx++;

        if (startIdx == grayCodes.length) startIdx = 0;
    }

    return res;
};