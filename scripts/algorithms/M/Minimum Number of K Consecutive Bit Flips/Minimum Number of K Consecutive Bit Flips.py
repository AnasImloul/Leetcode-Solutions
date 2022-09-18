# Runtime: 2365 ms (Top 19.91%) | Memory: 17.1 MB (Top 67.10%)
class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        flips = [0]*len(nums)
        csum = 0

        for left in range(0, len(nums)-k+1):
            if (nums[left] + csum) % 2 == 0:
                flips[left] += 1
                csum += 1
            if left >= k-1:
                csum -= flips[left-k+1]

        for check in range(len(nums)-k+1, len(nums)):
            if (nums[check] + csum) % 2 == 0:
                return -1
            if check >= k-1:
                csum -= flips[check-k+1]

        return sum(flips)
