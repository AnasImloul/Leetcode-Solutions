# Runtime: 65 ms (Top 20.14%) | Memory: 13.9 MB (Top 70.35%)
# Definition for singly-linked list.
# class ListNode:
# def __init__(self, val=0, next=None):
# self.val = val
# self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head == None:
            return None
        slow = head
        fast = head
        for i in range(n):
            fast = fast.next
        if fast == None:
            return head.next
        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next
        slow.next = slow.next.next
        return head