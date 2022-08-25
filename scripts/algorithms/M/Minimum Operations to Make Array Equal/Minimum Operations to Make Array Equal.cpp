// Runtime: 7 ms (Top 23.02%) | Memory: 5.9 MB (Top 36.86%)
class Solution {
public:
    int minOperations(int n) {
        int s=0;
        for(int i=0; i<= (n-1)/2; ++i){
            s += fabs(n-(2*i+1));
        }
        return s;
    }
};