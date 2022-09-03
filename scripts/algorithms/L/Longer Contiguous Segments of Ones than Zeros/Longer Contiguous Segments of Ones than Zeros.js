// Runtime: 63 ms (Top 99.07%) | Memory: 42.3 MB (Top 75.00%)
var checkZeroOnes = function(s) {
    let longest1 = 0;
    let longest0 = 0;

    let count1 = 0;
    let count0 = 0;

    for (let i = 0; i < s.length; i++) {
        const bit = s.charAt(i);

        if (bit === "1") count1++;
        else count1 = 0;

        if (bit === "0") count0++;
        else count0 = 0;

        longest1 = Math.max(longest1, count1);
        longest0 = Math.max(longest0, count0);
    }

    return longest1 > longest0;
};