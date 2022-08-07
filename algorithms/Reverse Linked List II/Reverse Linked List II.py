# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        # revrese api
        def reverse(start, end):
            prev = None
            cur = start
            while prev != end:
                nextNode = cur.next
                cur.next = prev
                prev = cur
                cur = nextNode
            return prev
        
        if not head or not head.next or right <= left:
            return head
        
        start, end = head, head
        node, afterRight = 0, 0
        
        # At the begining
        if left == 1:
            # start index 
            inc = left-1
            while inc > 0:
                start = start.next
                inc -= 1
            # end index
            inc = right-1
            while inc > 0:
                end = end.next
                inc -= 1
            afterRight = end.next
            reverse(start, end)
            head = end
        else: # Left other then begining
            # start index 
            inc = left-2
            while inc > 0:
                start = start.next
                inc -= 1
            # end index
            inc = right-1
            while inc > 0:
                end = end.next
                inc -= 1
            afterRight = end.next
            begin = start # node before left
            start = start.next
            reverse(start, end)
            begin.next = end
            
        # If their's ll chain left agter right chain it to the updated ll
        if afterRight:
            start.next = afterRight

        return head
    
"""
TC : O(n)
Sc : O(1)

"""
