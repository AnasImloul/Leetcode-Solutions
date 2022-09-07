# Runtime: 4322 ms (Top 46.43%) | Memory: 18 MB (Top 47.62%)
class Solution:
    def countSpecialSubsequences(self, nums: List[int]) -> int:
        if not nums:
            return 0

        last_0 = 0
        last_1 = 0
        last_2 = 0

        for i in nums:
            if i == 0:
                last_0 = (2*last_0 + 1)% 1000000007
            elif i == 1:
                last_1 = (last_0 + 2*last_1) % 1000000007
            elif i == 2:
                last_2 = (last_1 + 2*last_2) % 1000000007
        return last_2 % 1000000007