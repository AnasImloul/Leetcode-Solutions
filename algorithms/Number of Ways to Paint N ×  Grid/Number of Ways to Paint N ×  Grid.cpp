class Solution {
public:
    int numOfWays(int n) {
        int mod=1e9+7;
        long long c2=6,c3=6;
        for(int i=2;i<=n;i++){
            long long temp=c3;
            c3=(2*c3+2*c2)%mod;
            c2=(2*temp+3*c2)%mod;
        }
        return (c2+c3)%mod;
    }
};
