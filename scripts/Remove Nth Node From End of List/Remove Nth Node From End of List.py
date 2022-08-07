class Solution:
def removeNthFromEnd(self, head: Optional, n: int) -> Optional[ListNode]:
    a = b = head
    for _ in range(n):
        b = b.next
    if not b:
        return head.next
    while b.next:
        a = a.next
        b = b.next
    a.next = a.next.next
    return head