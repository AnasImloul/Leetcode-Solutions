# Runtime: 40 ms (Top 46.94%) | Memory: 20.50 MB (Top 100.00%)

class Solution:
    def countKSubsequencesWithMaxBeauty(self, s: str, k: int) -> int:

        mod = 1_000_000_007
        ctr = Counter(s)
        if len(ctr) < k: return 0

        _, cnt = zip(*ctr.most_common(k))
        mn = cnt[-1]
        needed, numMn = cnt.count(mn), list(ctr.values()).count(mn)

        ans = reduce(mul,filter(lambda x: x != mn, cnt), 1) %mod
        ans*= pow(mn, needed) * comb(numMn, needed) %mod

        return ans %mod
