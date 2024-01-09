// Runtime: 2 ms (Top 48.87%) | Memory: 6.20 MB (Top 75.88%)

class Solution {
public:
    int getSum(int a, int b) {
        unsigned int buff;
        do {
            buff = a & b;
            a ^= b;
            b = buff << 1;
        } while(buff);
        return a;
    }
};
