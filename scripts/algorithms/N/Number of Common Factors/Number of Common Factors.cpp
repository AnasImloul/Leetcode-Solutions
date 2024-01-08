// Runtime: 0 ms (Top 100.0%) | Memory: 6.30 MB (Top 37.62%)

class Solution {
public:
    int commonFactors(int a, int b) {
        int cf = 0;
        int m = min(a, b);
        for(int i = 1; i <= m; i++) {
            if(a % i == 0 && b % i == 0)
                cf++;
        }
        return cf;
    }
};
