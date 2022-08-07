/**
 * @param {number} n
 * @return {number}
 */
var largestPalindrome = function(n) {
    if (n === 1) return 9;
    let hi = BigInt(Math.pow(10, n) - 1);
    let num = hi;
    while(num > 0) {
        num -= 1n;
        const palindrome = BigInt(String(num) + String(num).split('').reverse().join(''));
        for (let i = hi; i >= 2n; i -= 2n) {
            const j = palindrome / i; 
            if (j > hi) break;
            if (palindrome % i === 0n) {
                return String(palindrome % 1337n);
            };
        }
    }
};
