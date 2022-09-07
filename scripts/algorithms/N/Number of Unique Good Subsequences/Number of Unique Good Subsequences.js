// Runtime: 115 ms (Top 44.44%) | Memory: 45.8 MB (Top 33.33%)
const MOD = 1000000007;

var numberOfUniqueGoodSubsequences = function(binary) {
    let endsZero = 0;
    let endsOne = 0;
    let hasZero = 0;
    for (let i = 0; i < binary.length; i++) {
        if (binary[i] === '1') {
            endsOne = (endsZero + endsOne + 1) % MOD;
        } else {
            endsZero = (endsZero + endsOne) % MOD;
            hasZero = 1;
        }
    }
    return (endsZero + endsOne + hasZero) % MOD;
};