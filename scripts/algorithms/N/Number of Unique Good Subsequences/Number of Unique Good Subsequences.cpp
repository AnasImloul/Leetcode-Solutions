class Solution {
    int MOD = 1000000007;
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int zero = 0;
        long long ones = 0;
        long long zeros = 0;
        
        for (int i = binary.size() - 1; i >= 0; --i) {
            if (binary[i] == '1') {
                ones = (ones + zeros + 1) % MOD;
            } else {
                zero = 1;
                zeros = (ones + zeros + 1) % MOD;
            }
        }
        return (ones + zero) % MOD;
    }
};
