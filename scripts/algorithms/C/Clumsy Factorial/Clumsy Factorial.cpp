// Runtime: 0 ms (Top 100.00%) | Memory: 5.9 MB (Top 74.03%)

class Solution {
public:
    int calc(int num) {
        int a = num, b = num-1, c = num-2;
        return a*b/c;
    }
    int clumsy(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 6;
        int res = calc(n), i;
        res += n-3;
        for(i=n-4;i>=4;i-=4) {
            int val = calc(i);
            res -= val; res += i-3;
        }
        if(i == 1) return res -1;
        else if(i==2) return res - 2;
        else if(i==3) return res - 6;
        return res;
    }
};