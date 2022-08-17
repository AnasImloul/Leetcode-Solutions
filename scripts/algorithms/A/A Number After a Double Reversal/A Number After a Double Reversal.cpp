class Solution {
public:
    bool isSameAfterReversals(int num) {
        return num == 0 || num % 10 > 0; // All you have to do is check the Trailing zeros
    }
};
