class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        acc = list(accumulate(nums))
        ans = a = 0
        for n in nums:
            a += n
            ans += sum(1 for x in acc if lower <= x <= upper)
            acc.pop(0)
            lower += n
            upper += n
        return ans
