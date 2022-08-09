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
