class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        element_sum = sum(nums)
        digit_sum = 0
        all_digits  = "".join([str(digit) for digit in nums])
        for digit in all_digits:
            digit_sum += int(digit)
        return abs(element_sum-digit_sum)