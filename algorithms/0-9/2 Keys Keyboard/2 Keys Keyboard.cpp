class Solution {
public:
    int minSteps(int n) {
        for (int j = n/2; j >= 1; j--) {
            if (n % j == 0) {
                return minSteps(j) + n/j;
            }
        }
        return 0;
    }
};
