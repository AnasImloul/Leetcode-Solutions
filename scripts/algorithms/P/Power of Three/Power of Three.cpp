// Runtime: 44 ms (Top 25.15%) | Memory: 5.9 MB (Top 73.44%)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)return false;
        if(n==1)return true;
        if(n % 3 == 0){
            return isPowerOfThree(n/3);
        }
        return false;
    }
};