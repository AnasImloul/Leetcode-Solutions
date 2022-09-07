// Runtime: 14 ms (Top 38.08%) | Memory: 41.3 MB (Top 54.72%)
class Solution {
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        long mod = 1000000007L;
        long[] shares = new long[n + 1];
        long[] forgets = new long[n + 1];

        if (delay < n) {
            shares[delay + 1] = 1;
        }
        if (forget < n) {
            forgets[forget + 1] = 1;
        }

        long shareToday = 0;
        long peopleKnow = 1;
        for (int i = delay; i <= n; i++) {
            shareToday += shares[i] % mod;
            shareToday -= forgets[i] % mod;

            peopleKnow -= forgets[i] % mod;
            peopleKnow += shareToday % mod;

            if (i + delay < n + 1) {
                shares[i + delay] += shareToday % mod;
            }
            if (i + forget < n + 1) {
                forgets[i + forget] += shareToday % mod;
            }
        }

        return (int) (peopleKnow % mod);
    }
}