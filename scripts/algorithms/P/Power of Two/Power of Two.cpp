// Runtime: 4 ms (Top 41.31%) | Memory: 6 MB (Top 27.35%)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        while(n%2==0) n/=2;
        return n==1;
    }
};