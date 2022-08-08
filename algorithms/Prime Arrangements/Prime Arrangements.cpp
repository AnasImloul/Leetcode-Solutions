class Solution {
public:
    bool isPrime(int x) {
        if(x <= 3) return x > 1;
        if(x % 2 == 0) return false;
        
        for(int i = 3; i <= sqrt(x); i += 2) {
            if(x % i == 0) return false;
        }
        return true;
    }
    
    int fact(int x) {
        if(x <= 1) return 1;
        return ((long long)(x) * fact(x - 1)) % 1000000007;
    }
    
    int numPrimeArrangements(int n) {
        int c = 0;
        for(int i = 1; i <= n; ++i) {
            c += isPrime(i);
        }
        return ((long long)(fact(n - c)) * fact(c)) % 1000000007;
    }
};
