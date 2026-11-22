# Runtime: 127 ms (Top 30.67%) | Memory: 34.30 MB (Top 20.67%)

class Solution:
  def minimumSum(self, nums: List[int]) -> int:
    min_l = [nums[0]] * len(nums)
    min_r = [nums[-1]] * len(nums)

    for i in range(1, len(nums)):
      min_l[i] = min(min_l[i - 1], nums[i])
    for i in range(len(nums) - 2, -1, -1):
      min_r[i] = min(min_r[i + 1], nums[i])

    res = float('inf')
    for i in range(1, len(nums) - 1):
      if nums[i] > min_l[i - 1] and nums[i] > min_r[i + 1]:
        res = min(res, nums[i] + min_l[i - 1] + min_r[i + 1])
    return -1 if res == float('inf') else res
