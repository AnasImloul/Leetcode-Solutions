class Solution {
public:
    int makeStringSorted(string s) {
        int freq[26] = {}, n = size(s), MOD = 1'000'000'007; 
        for (auto& c : s) ++freq[c - 'a']; 
        
        auto power = [](long x, int p, int m) {
            long ans = 1; 
            while (p) {
                if (p&1) {
                    ans = (ans * x) % m; 
                    p -= 1; 
                } else {
                    x = (x * x) % m; 
                    p /= 2; 
                } 
            }
            return ans; 
        };
        
        long ans = 0, fac = 1; 
        vector<long> ifac(n+1, 1); // +1 buffer 
        
        for (int i = 1; i < n; ++i) {
            fac = fac * i % MOD; 
            ifac[i] = power(fac, MOD-2, MOD); // Fermat's little theorem
        }
        
        for (auto& x : freq) fac = fac * ifac[x] % MOD; 
        
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < s[i] - 'a'; ++k) 
                ans = (ans + fac * freq[k]) % MOD; 
            fac = fac * power(n-i-1, MOD-2, MOD) % MOD; 
            fac = fac * freq[s[i] - 'a'] % MOD; 
            --freq[s[i] - 'a']; 
        }
        return ans; 
    }
};
