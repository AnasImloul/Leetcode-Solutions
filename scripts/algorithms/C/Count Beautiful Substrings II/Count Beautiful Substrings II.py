# Runtime: 305 ms (Top 5.88%) | Memory: 24.00 MB (Top 11.76%)

class Solution:
    def beautifulSubstrings(self, S: str, K: int) -> int:
        P = [0]
        for c in S:
            P.append(P[-1] + (1 if c in "aeiou" else -1))

        K_new = 1
        for p in range(2, 1000):
            e = 0
            while K % p == 0:
                K //= p
                e += 1

            if e:
                e = (e + 1) // 2 + (p == 2)
                K_new *= p**e

        K = K_new
        count = Counter()
        ans = 0
        for i, p in enumerate(P):
            ans += count[p, i % K]
            count[p, i % K] += 1
        return ans
