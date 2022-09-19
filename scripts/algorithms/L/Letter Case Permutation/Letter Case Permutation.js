// Runtime: 99 ms (Top 77.76%) | Memory: 45.1 MB (Top 64.02%)
const sliceRemaining = (s) => s.slice(1, s.length);

var letterCasePermutation = function(s) {
    let output = [];

    const backtracking = (current, remaining) => {
        if (!remaining.length) return output.push(current);

        if (/^[0-9]+$/i.test(remaining[0])) {
            current += remaining[0];
            backtracking(current, sliceRemaining(remaining));
        } else {
            backtracking(current + remaining[0].toLowerCase(), sliceRemaining(remaining));

            backtracking(current + remaining[0].toUpperCase(), sliceRemaining(remaining));
        }
    }
    backtracking('', s);

    return output;
};