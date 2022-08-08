class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # basically we create two pointers
        # move one pointer extra fast
        # another pointer would be slow
        # when fast reaches end slow would be in mid
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow
