// Runtime: 0 ms (Top 100.00%) | Memory: 5.8 MB (Top 70.14%)
class Solution {
public:
    int mirrorReflection(int p, int q) {
        while (p % 2 == 0 && q % 2 == 0){
            p/=2;
            q/=2;
        }
        return 1 - p % 2 + q % 2;
    }
};