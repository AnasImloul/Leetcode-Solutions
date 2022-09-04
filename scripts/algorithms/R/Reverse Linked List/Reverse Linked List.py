# Runtime: 71 ms (Top 18.71%) | Memory: 15.5 MB (Top 28.33%)
# Definition for singly-linked list.
# class ListNode:
# def __init__(self, val=0, next=None):
# self.val = val
# self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None or head.next==None:
            return head
        p = None
        while(head != None):
            temp = head.next
            head.next = p
            p = head
            head = temp
        return p
