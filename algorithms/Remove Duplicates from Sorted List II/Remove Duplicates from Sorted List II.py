# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if (not head):
            return None

        result = tail = ListNode(-1)

        while(head):
            curr = head
            head = head.next
            hasDup = False
            while(head) and (curr.val == head.val):
                hasDup = True
                headNext = head.next
                head = None
                head = headNext

            if (hasDup == False):
                tail.next = curr
                tail = tail.next
                tail.next = None

        return result.next

