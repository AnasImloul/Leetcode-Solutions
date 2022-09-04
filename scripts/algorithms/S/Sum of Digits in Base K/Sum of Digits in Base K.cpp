// Runtime: 0 ms (Top 100.00%) | Memory: 5.8 MB (Top 72.89%)
class Solution {
public:
    int sumBase(int n, int k) {
        int sum=0;
        while(n!=0) sum+=n%k,n=n/k;
        return sum;
    }
};