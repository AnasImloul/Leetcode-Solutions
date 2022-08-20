// Runtime: 0 ms (Top 100.00%) | Memory: 6 MB (Top 50.88%)

class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9+7;
        long long ans = 1;
        for(int i=1;i<=n;i++){
            int m = 2*i-1;
            int p = (m*(m+1))/2;
            ans=(ans*p)%mod;
        }
        return ans;
    }
};