// Runtime: 10 ms (Top 11.29%) | Memory: 6 MB (Top 29.05%)
class Solution {
public:
    int divide(int dividend, int divisor) {
        if((dividend == INT_MIN)&&(divisor == -1)) return INT_MAX;
        return dividend/divisor;
    }
};