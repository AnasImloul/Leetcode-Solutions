// Runtime: 0 ms (Top 100.00%) | Memory: 6 MB (Top 5.99%)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start^goal);
    }
};