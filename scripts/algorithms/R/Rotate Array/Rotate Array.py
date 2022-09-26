# Runtime: 484 ms (Top 40.41%) | Memory: 25.4 MB (Top 28.89%)
class Solution:
    def reverse(self,arr,left,right):
        while left < right:
            arr[left],arr[right] = arr[right], arr[left]
            left, right = left + 1, right - 1
        return arr
    def rotate(self, nums: List[int], k: int) -> None:
        length = len(nums)
        k = k % length
        l, r = 0, length - 1
        nums = self.reverse(nums,l,r)
        l, r = 0, k - 1
        nums = self.reverse(nums,l,r)
        l, r = k, length - 1
        nums = self.reverse(nums,l,r)
        return nums