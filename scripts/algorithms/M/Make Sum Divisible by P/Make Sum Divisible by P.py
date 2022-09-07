# Runtime: 824 ms (Top 50.97%) | Memory: 32.5 MB (Top 61.17%)
class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        r = sum(nums)%p
        if r == 0: return 0

        d = {0:-1}
        s = 0
        ans = None

        for i, n in enumerate(nums):
            s = (s+n)%p

            # save all possible remainder with latest index only
            d[s] = i

            # search the target remainder with index closest to current i
            # s is the current remainder so we can derive such relation:
            # s - target = r (mod p) => target = s-r (mod p)
            target = (s-r)%p
            if target in d:
                a = i - d[target]
                if ans is None: ans = a
                else: ans = min(ans, a)
        if ans == len(nums) or ans is None: return -1
        return ans
