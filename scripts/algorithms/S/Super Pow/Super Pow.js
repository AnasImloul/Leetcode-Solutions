// Runtime: 100 ms (Top 64.52%) | Memory: 42.9 MB (Top 64.52%)
var superPow = function(a, b) {
    const MOD = 1337;
    const pow = (num, n) => {
        let result = 1;
        for (let index = 0; index < n; index++) {
            result = result * num % MOD;
        }
        return result;
    };

    return b.reduceRight((result, n) => {
        a %= MOD;
        const powNum = result * pow(a, n) % MOD;

        a = pow(a, 10);
        return powNum;
    }, 1);
};