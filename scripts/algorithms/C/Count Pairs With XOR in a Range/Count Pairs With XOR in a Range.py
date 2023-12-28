// Runtime: 1588 ms (Top 85.61%) | Memory: 20.60 MB (Top 80.3%)

class Solution:
    def countPairs(self, nums, low, high):
        return self._countPairs(nums, high + 1) - self._countPairs(nums, low)
    
    def _countPairs(self, nums, high):
        res = 0
        for k in range(31, -1, -1):
            target = high >> k
            if target & 1 == 0:
                continue
            target -= 1
            counter = Counter(num >> k for num in nums)
            for mask in counter:
                res += counter[mask] * counter[target ^ mask]
                if mask == target ^ mask:
                    res -= counter[mask]
        return res // 2
