// Runtime: 120 ms (Top 92.63%) | Memory: 114.00 MB (Top 34.74%)

typedef long long ll; 

class Solution {
public:
    long long minimumTotalCost(vector<int>& a, vector<int>& b) {
        int n = a.size(); 
        vector<int> f(n+1, 0); 
        for (int i = 0; i < n; ++i) {
            f[a[i]]++; 
            f[b[i]]++; 
        }
        for (int i = 1; i <= n; ++i) {
            if (f[i] > n) return -1; 
            f[i] = 0; 
        }
        vector<int> c; 
        int mx = 0, val = 0, mn = 1e9; 
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i]) {
                c.push_back(i); 
                f[a[i]] += 2; 
                mn = min(mn, i); 
                if (f[a[i]] > mx) {
                    mx = f[a[i]]; 
                    val = a[i]; 
                }
            }
        }
        
        if (mx > (int) c.size()) {
            for (int i = 0; i < n; ++i) {
                if (a[i] != val && b[i] != val && a[i] != b[i]) {
                    c.push_back(i); 
                    mn = min(mn, i);
                    if (mx <= (int) c.size()) {
                        break; 
                    }
                }
            }
        }
        
        long long ans = 0; 
        for (int i = 0; i < (int)c.size(); ++i) ans += c[i]; 
        
        return ans; 
        
    }
};
