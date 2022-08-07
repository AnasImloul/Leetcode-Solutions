Time: O(n*n1)  Space: O(n)

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n==1)
            return 1;
        vector<long long int> dp(n);
        dp[0]=1;
        int n1=size(primes);
        vector<int> p(n1);
        for(int i=1;i<n;i++){
             long long int x=INT_MAX;
            for(int j=0;j<n1;j++){
                x=min(x,primes[j]*dp[p[j]]);
            }
            dp[i]=x;
            for(int j=0;j<n1;j++){
                if(x==primes[j]*dp[p[j]])
                    p[j]++;
            }
        }
        return dp[n-1];
    }
};
