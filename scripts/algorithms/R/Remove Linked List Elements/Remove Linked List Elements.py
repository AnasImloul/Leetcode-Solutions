# Runtime: 151 ms (Top 10.13%) | Memory: 17.7 MB (Top 81.63%)
# Definition for singly-linked list.
# class ListNode:
# def __init__(self, val=0, next=None):
# self.val = val
# self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        prev=head
        cur=head
        while cur is not None:
            if cur.val==val:
                if cur==head:
                    head=head.next
                    prev=head
                else:
                    prev.next=cur.next
            else:
                prev=cur
            cur=cur.next
        return head