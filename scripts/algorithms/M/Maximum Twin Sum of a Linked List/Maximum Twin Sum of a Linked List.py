# Runtime: 2246 ms (Top 8.54%) | Memory: 54.1 MB (Top 58.68%)
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        nums = []
        curr = head
        while curr:
            nums.append(curr.val)
            curr = curr.next

        N = len(nums)
        res = 0
        for i in range(N // 2):
            res = max(res, nums[i] + nums[N - i - 1])
        return res