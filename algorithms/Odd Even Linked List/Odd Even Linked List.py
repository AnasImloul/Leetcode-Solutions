class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return 
        odd, even_start, even = head, head.next, head.next
        while odd is not None and even is not None:
            odd.next = even.next
            if odd.next is not None:
                odd = odd.next
                even.next = odd.next
                even = even.next
            else:
                break
        odd.next = even_start
        return head
