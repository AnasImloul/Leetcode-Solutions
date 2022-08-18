# Runtime: 2052 ms (Top 44.44%) | Memory: 32.2 MB (Top 22.19%)

class Solution:
    def countExcellentPairs(self, nums: List[int], k: int) -> int:
        hamming = sorted([self.hammingWeight(num) for num in set(nums)])
        ans = 0
        for h in hamming:
            ans += len(hamming) - bisect.bisect_left(hamming, k - h)
        return ans

    def hammingWeight(self, n):
        ans = 0
        while n:
            n &= (n - 1)
            ans += 1
        return ans