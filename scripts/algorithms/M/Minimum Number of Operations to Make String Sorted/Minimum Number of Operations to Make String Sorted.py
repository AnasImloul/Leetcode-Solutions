from math import gcd

class Solution:
    def makeStringSorted(self, s: str) -> int:
        s = [ord(c) - ord('a') for c in s]
        ans, MOD = 0, 10 ** 9 + 7
        cnt, t, d, step = [0] * 26, 1, 1, 1
        cnt[s[-1]] = 1
        for c in reversed(s[:-1]):
            d *= (cnt[c] + 1)
            t *= step
            g = gcd(d, t)
            d //= g
            t //= g
            ans = (ans + t * sum(cnt[i] for i in range(c)) // d) % MOD
            cnt[c] += 1
            step += 1
        return ans