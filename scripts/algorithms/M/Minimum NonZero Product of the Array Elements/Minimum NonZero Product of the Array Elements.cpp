// Runtime: 2 ms (Top 44.8%) | Memory: 6.13 MB (Top 5.6%)

// class Solution {
// private:
//     long long pow(long long nums, long long p) {
//         if (p == 0) {
//             return 1;
//         }
//        // long long M = pow(10, 9) + 7;
//        const int M = 1000000007;
//         long long temp = pow(nums, p / 2);
//         if (p % 2 == 0) {
//             return (temp * temp) % M;
//         } else {
//             return (((temp * temp) % M) * (nums % M)) % M;
//         }
//     }

// public:
//     int minNonZeroProduct(int p) {
//         long long M = pow(10, 9) + 7;
//         long long maxVal = pow(2, p) - 1;
//         long long power = pow(maxVal - 1, (maxVal - 1) / 2);
//         power = ((power % M) * (maxVal % M)) % M;

//         return static_cast<int>(power);
//     }
// };





class Solution {
private:
    const int MOD = 1000000007;

    long long power(long long x, long long y)
    {
        if (y == 0)
            return 1;
        long long ans = power(x, y / 2);
        if (y % 2 == 0)
            return (ans * ans) % MOD;
        else
            return (((ans * ans) % MOD) * (x % MOD)) % MOD;
    }

public:
    int minNonZeroProduct(int p) {
        long long max_i = pow(2, p);
        long long max = max_i - 1;
        long long result = power((max - 1), ((max - 1) / 2));
        return (result * (max % MOD)) % MOD;
    }
};