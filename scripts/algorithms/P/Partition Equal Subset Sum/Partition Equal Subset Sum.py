// Runtime: 437 ms (Top 80.03%) | Memory: 18.00 MB (Top 70.21%)

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        dp, s = set([0]), sum(nums)
        if s&1:
            return False
        for num in nums:
            for curr in range(s>>1, num-1, -1):
                if curr not in dp and curr-num in dp:
                    if curr == s>>1:
                        return True
                    dp.add(curr)
        return False
