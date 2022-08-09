int comb[10001][14] = { 1 }, cnt[10001][14] = {}, mod = 1000000007;
class Solution {
public: 
int idealArrays(int n, int maxValue) {
    if (comb[1][1] == 0) { // one-time computation.
        for (int s = 1; s <= 10000; ++s) // nCr (comb)
            for (int r = 0; r < 14; ++r)
                comb[s][r] = r == 0 ? 1 : (comb[s - 1][r - 1] + comb[s - 1][r]) % mod;
        for (int div = 1; div <= 10000; ++div) { // Sieve of Eratosthenes
            ++cnt[div][0];
            for (int i = 2 * div; i <= 10000; i += div)
                for (int bars = 0; cnt[div][bars]; ++bars)
                    cnt[i][bars + 1] += cnt[div][bars];
        }
    }
    int res = 0;
    for (int i = 1; i <= maxValue; ++i)
        for (int bars = 0; bars < min(14, n) && cnt[i][bars]; ++bars)
            res = (1LL * cnt[i][bars] * comb[n - 1][bars] + res) % mod;
    return res;
}
};
