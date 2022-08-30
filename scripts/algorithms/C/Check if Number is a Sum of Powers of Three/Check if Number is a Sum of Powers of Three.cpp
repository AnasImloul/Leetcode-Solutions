// Runtime: 0 ms (Top 100.00%) | Memory: 5.9 MB (Top 49.47%)
class Solution {
public:
    bool checkPowersOfThree(int n) {
        // grinding n down by powers of 3
        while (n) {
            if (n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};