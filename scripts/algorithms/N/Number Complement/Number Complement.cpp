// Runtime: 0 ms (Top 100.00%) | Memory: 5.8 MB (Top 78.74%)
class Solution {
public:
    int findComplement(int num) {
        long n=1;
        while(n-1<num)
        {
            n<<=1;
        }
        n--;
        return n-num;
    }
};