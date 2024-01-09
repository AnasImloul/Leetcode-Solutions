// Runtime: 0 ms (Top 100.0%) | Memory: 6.20 MB (Top 76.14%)

class Solution {
public:
    int numberOfCuts(int n) {
        if(n == 1){
            return 0;
        }
        if(n%2 == 0){
            return n/2;
        }
        return n;
        
    }
};
