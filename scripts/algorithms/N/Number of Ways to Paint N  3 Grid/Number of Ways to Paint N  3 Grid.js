// Runtime: 50 ms (Top 93.1%) | Memory: 44.10 MB (Top 37.93%)

/*
cur123: the total number of ways of painting the grid from first row to current row where current row is 3-colored
cur121: the total number of ways of painting the grid from first row to current row where current row is 2-colored

Possible 123-pattern arrangements after row of 123 pattern: 2
Possible 123-pattern arrangements after row of 121 pattern: 2

Possible 121-pattern arrangements after row of 123 pattern: 2
Possible 121-pattern arrangements after row of 121 pattern: 3

Hence, cur123 = prev123 * 2 + prev121 * 2 and cur121 = prev123 * 2 + prev121 * 3
*/

var numOfWays = function(n) {
    const MOD = Math.pow(10, 9) + 7;
    let prev123 = 6, prev121 = 6, total = 12;
    for (let i = 2; i <= n; i++) {
        let cur123 = (prev123 * 2 + prev121 * 2) % MOD;
        let cur121 = (prev123 * 2 + prev121 * 3) % MOD;
        total = (cur123 + cur121) % MOD;
        prev123 = cur123;
        prev121 = cur121;
    }
    return total;
    // T.C: O(N)
    // S.C: O(1)
};
