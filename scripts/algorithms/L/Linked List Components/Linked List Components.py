# Runtime: 171 ms (Top 62.36%) | Memory: 19.1 MB (Top 64.07%)
class Solution:
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        d,count={},0
        for num in nums:
            d[num] = 0

        while head:
            if head.val in d:
                head = head.next
                while head and head.val in d:
                    head = head.next
                count += 1
            else:
                head = head.next
        return count