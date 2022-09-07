// Runtime: 2 ms (Top 45.45%) | Memory: 5.9 MB (Top 68.90%)
class Solution {
public:
    const static uint32_t a = 0b10101010101010101010101010101010;
    bool hasAlternatingBits(int n) {
        return ((a >> __builtin_clz(n)) ^ n) == 0;
    }
};