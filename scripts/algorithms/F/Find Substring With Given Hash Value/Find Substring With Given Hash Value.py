# Runtime: 996 ms (Top 33.98%) | Memory: 14.1 MB (Top 94.23%)
class Solution:
    def subStrHash(self, s: str, power: int, mod: int, k: int, hashValue: int) -> str:
        val = lambda ch : ord(ch) - ord("a") + 1
        hash, res, power_k = 0, 0, pow(power, k, mod)
        for i in reversed(range(len(s))):
            hash = (hash * power + val(s[i])) % mod
            if i < len(s) - k:
                hash = (mod + hash - power_k * val(s[i + k]) % mod) % mod
            res = i if hash == hashValue else res
        return s[res:res + k]