// Runtime: 0 ms (Top 100.0%) | Memory: 6.20 MB (Top 76.33%)

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int num = x^y;
        while (num) {
            res += num % 2;
            num >>= 1;
        }
        return res;
    }
};
