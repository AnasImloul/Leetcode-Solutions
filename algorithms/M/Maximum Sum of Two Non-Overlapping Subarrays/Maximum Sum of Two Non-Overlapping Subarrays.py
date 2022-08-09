class Solution:
    def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:
        n = len(nums)
        p = [0]
        for el in nums:
            p.append(p[-1] + el)
        msum = 0
        for f, s in [(firstLen, secondLen), (secondLen, firstLen)]:
            for i in range(f - 1, n - s + 1):
                for j in range(i + 1, n - s + 1):
                    l = p[i + 1] - p[i - f + 1]
                    r = p[j + s] - p[j]
                    msum = max(msum, l + r)
        return msum
