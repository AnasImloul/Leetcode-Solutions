# Runtime: 144 ms (Top 22.58%) | Memory: 39.80 MB (Top 67.74%)

class Solution:
    def numberOfGoodPartitions(self, nums: List[int], cnt = 0) -> int:

        d, s = {num:i for i, num in enumerate(nums)}, set()

        for i, num in enumerate(nums):
            s.add(num)
            if d[num] == i: s.remove(num)
            cnt+= (len(s) == 0)

        return pow(2, cnt - 1, 1_000_000_007)
