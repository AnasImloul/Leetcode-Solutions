from functools import cmp_to_key
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = list(map(str, nums))
        nums = reversed(sorted(nums, key = cmp_to_key(lambda x, y: -1 if int(x+y) < int(y+x) else ( 1 if int(x+y) > int(y+x) else 0))))
        res = "".join(nums)
        return res if int(res) else "0"