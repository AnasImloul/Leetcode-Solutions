# Runtime: 159 ms (Top 92.68%) | Memory: 152.00 MB (Top 7.32%)

MOD = 10 ** 9 + 7
@cache
def fact(i: int) -> int:
    return 1 if i < 2 else i * fact(i - 1) % MOD
@cache
def ifact(i: int) -> int:
    return pow(fact(i), -1, MOD)
class Solution:
    def numberOfSequence(self, n: int, sick: List[int]) -> int:
        res = fact(n - len(sick)) * ifact(sick[0]) * ifact(n - sick[-1] - 1) % MOD
        for group in [b - a - 1 for a, b in pairwise(sick) if b - a > 1]:
            res = res * ifact(group) % MOD
            res = res * pow(2, group - 1, MOD) % MOD
        return res
