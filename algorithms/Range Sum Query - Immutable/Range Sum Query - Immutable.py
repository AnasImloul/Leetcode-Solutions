class NumArray:

    def __init__(self, nums: List[int]):
        self.nums, Sum = [], 0
        for num in nums:
            Sum += num
            self.nums.append(Sum)

    def sumRange(self, left: int, right: int) -> int:
        return self.nums[right] - self.nums[left - 1] if left - 1 >= 0 else self.nums[right]
