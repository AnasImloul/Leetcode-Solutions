class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        nums = sorted(map(int, nums), reverse=True)
        return str(nums[k-1])
