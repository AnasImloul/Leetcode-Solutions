// Runtime: 13 ms (Top 80.40%) | Memory: 5.8 MB (Top 81.91%)
class Solution {

public:
    bool isPrime(int N) {
    if (N < 2) return false;
    int R = (int)sqrt(N);
    for (int d = 2; d <= R; ++d)
        if (N % d == 0) return false;
    return true;
    }

public:
    int reverse(int N) {
    int ans = 0;
    while (N > 0) {
        ans = 10 * ans + (N % 10);
           N /= 10;
        }
    return ans;
    }
public:
    int primePalindrome(int n) {
        while (true) {
            if (n == reverse(n) && isPrime(n))
                return n;
            n++;

            // Any even length palindrome must be divisble by 11
            // so we will skip numbers N = [10,000,000, 99,999,999]
            if (10000000 < n && n < 100000000)
                n = 100000000;
        }
    }
};