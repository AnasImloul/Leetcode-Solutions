class Solution {
public:
    int power(long long base, int pow){
        if(pow==0)return 1;
        return (pow&1?(base*power(base,pow-1))%1000000007:power((base*base)%1000000007,pow/2))%1000000007;
    }
    int maxNiceDivisors(int primeFactors) {
        long ans = 1;
        if(primeFactors%3==1&&primeFactors>1){
            ans  = 4;
            primeFactors -= 4;
        }
        else if(primeFactors%3==2){
            ans =2;
            primeFactors-=2;
        }
        return (power(3,primeFactors/3)*ans)%1000000007;
    }
};
