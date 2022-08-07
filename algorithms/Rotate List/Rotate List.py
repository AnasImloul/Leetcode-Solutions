# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if k==0 or head is None or head.next is None:
            return head
        cur=head
        n=0
        while cur is not None:
            cur=cur.next
            n+=1
        k=n-k%n
        if k==n:
            return head
        cur=head
        prev=None
        while k>0 and cur is not None:
            prev=cur
            cur=cur.next
            k-=1
        prev.next=None
        prev=cur
        while cur.next is not None:
            cur=cur.next
        cur.next=head
        return prev
        
