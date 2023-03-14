class Solution {
public:
    int addDigits(int n) {
        return n < 10 ? n : addDigits(n / 10 + n % 10);
    }
};