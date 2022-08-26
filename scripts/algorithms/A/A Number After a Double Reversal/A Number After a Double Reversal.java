// Runtime: 0 ms (Top 100.00%) | Memory: 38.6 MB (Top 100.00%)
class Solution {
    public boolean isSameAfterReversals(int num) {
        return num == 0 || num % 10 > 0; // All you have to do is check the Trailing zeros
    }
}