# Runtime: 33 ms (Top 81.50%) | Memory: 33.90 MB (Top 28.74%)

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        from collections import Counter
        mp = Counter(nums)

        count = 0
        for t in mp.values():
            if t == 1:
                return -1
            count += t // 3
            if t % 3:
                count += 1

        return count
