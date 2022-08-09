class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        if nums[start] == target: return 0
        left, right = start-1, start+1
        N = len(nums)
        while True:
            if left >=0 and nums[left] == target:
                return start - left
            if right < N and nums[right] == target:
                return right - start
            left -= 1
            right += 1
