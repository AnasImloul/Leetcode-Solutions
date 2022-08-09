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
