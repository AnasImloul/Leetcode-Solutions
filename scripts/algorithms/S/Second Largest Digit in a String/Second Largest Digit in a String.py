# Runtime: 80 ms (Top 5.3%) | Memory: 16.30 MB (Top 72.1%)

class Solution:
    def secondHighest(self, s: str) -> int:
        nums = []
        for char in s:
            if char.isdigit():
                nums.append(int(char))
        nums = [num for num in nums if num != max(nums)]
        if len(nums) >= 1: return max(nums)
        else: return -1