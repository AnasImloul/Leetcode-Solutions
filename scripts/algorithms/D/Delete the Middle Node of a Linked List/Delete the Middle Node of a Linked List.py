# Runtime: 2948 ms (Top 45.50%) | Memory: 60.7 MB (Top 40.45%)
# Definition for singly-linked list.
# class ListNode:
# def __init__(self, val=0, next=None):
# self.val = val
# self.next = next
class Solution:
  def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
    if not head: return head
    if head and not head.next: return None

    prev = ListNode(0, head)
    slow = fast = head
    while fast and fast.next:
      prev = slow
      slow = slow.next
      fast = fast.next.next

    prev.next = slow.next
    return head