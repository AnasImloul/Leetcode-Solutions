// Runtime: 13 ms (Top 88.46%) | Memory: 7.40 MB (Top 76.92%)

const int MOD = 1e9 + 7;
const int N = 3010;

long f[N];
long g[N];

long qmi(long a, int k) {
    long res = 1;
    while (k != 0) {
        if ((k & 1) == 1) {
            res = res * a % MOD;
        }
        k >>= 1;
        a = a * a % MOD;
    }
    return res;
}

int init = []() {
    f[0] = g[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i % MOD;
        g[i] = qmi(f[i], MOD - 2);
    }
    return 0;
}();

class Solution {
public:
    int makeStringSorted(string s) {
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        int n = s.size();
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            int m = 0;
            for (int j = 0; j < 26; ++j) {
                if (j < s[i] - 'a') {
                    m += cnt[j];
                }
            }
            long t = m * f[n - i - 1] % MOD;
            for (int j = 0; j < 26; ++j) {
                t = t * g[cnt[j]] % MOD;
            }
            ans = (ans + t) % MOD;
            --cnt[s[i] - 'a'];
        }
        return ans;
    }
};
