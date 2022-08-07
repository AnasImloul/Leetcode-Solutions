class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        n = len(nums)
        for i in range(n):
            seen = set()
            minval = float('inf')
            maxval = float('-inf')
            j = i
            while j not in seen:
                seen.add(j)
                minval = min(minval, nums[j])
                maxval = max(maxval, nums[j])
                k = 1 + abs(nums[j]) // n
                j = (k * n + j + nums[j]) % n
            if j == i and len(seen) > 1 and (minval > 0 or maxval < 0):
                return True
        return False
