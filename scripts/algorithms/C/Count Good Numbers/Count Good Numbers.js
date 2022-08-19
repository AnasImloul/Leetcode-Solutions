// Runtime: 120 ms (Top 15.79%) | Memory: 44.1 MB (Top 31.58%)

class Math1 {

    // https://en.wikipedia.org/wiki/Modular_exponentiation
    static modular_pow(base, exponent, modulus) {
        if (modulus === 1n)
            return 0n
        let result = 1n
        base = base % modulus
        while (exponent > 0n) {
            if (exponent % 2n == 1n)
                result = (result * base) % modulus
            exponent = exponent >> 1n
            base = (base * base) % modulus
        }
        return result
    }

}

var countGoodNumbers = function(n) {
    // NOTE: 0n, 1n, 2n, 3n, 4n, 5n are numbers in BigInt

    n = BigInt(n); // convert to BigInt, to avoid no rounding issues

    const odds = n / 2n,
        evens = n - odds,
        MOD = BigInt(Math.pow(10, 9) + 7)

    // from wikipedia
    return (Math1.modular_pow(4n, odds, MOD) * Math1.modular_pow(5n, evens, MOD)) % MOD;
};