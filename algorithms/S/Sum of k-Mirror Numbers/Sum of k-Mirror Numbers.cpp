class Solution {
public:
    long long kMirror(int k, int n) {
        
        auto palin = [](int n, bool odd) {
            long long ans = n; 
            if (odd) n /= 10; 
            for (; n; n /= 10) ans = 10*ans + n % 10; 
            return ans; 
        }; 
        
        auto is_mirror = [&](long long x) {
            long long rev = 0; 
            for (auto tmp = x; tmp; tmp /= k) rev = k*rev + tmp % k; 
            return x == rev; 
        }; 
        
        long long ans = 0, palin0 = 0, palin1 = 0; 
        int odd = 1, even = 1; 
        while (n--) {
            for (; true; ++odd) {
                palin1 = palin(odd, true); 
                if (is_mirror(palin1)) break; 
            }
            for (; palin0 < palin1; ++even) {
                palin0 = palin(even, false); 
                if (is_mirror(palin0)) break; 
            }
            if (palin0 < palin1) {
                ans += palin0; 
                ++even; 
            } else {
                ans += palin1; 
                ++odd; 
            }
        }
        return ans; 
    }
};
