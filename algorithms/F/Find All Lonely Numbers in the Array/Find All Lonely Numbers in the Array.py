class Solution:
    def findLonely(self, nums: List[int]) -> List[int]:
        m = Counter(nums)
        return [n for n in nums if m[n] == 1 and m[n - 1] + m[n + 1] == 0]
