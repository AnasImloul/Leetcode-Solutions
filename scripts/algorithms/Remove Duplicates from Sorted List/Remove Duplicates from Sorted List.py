# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head
        cur=head.next
        prev=head
        while cur is not None:
            if cur.val==prev.val:
                prev.next=cur.next
            else:
                prev=cur
            cur=cur.next
        return head
