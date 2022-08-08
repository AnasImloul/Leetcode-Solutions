# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        res = 0
        po = 0
        stack = []
        node = head
        while node:
            stack.append(node.val)
            node = node.next
        res = 0
        for i in reversed(stack):
            res += i*(2**po)
            po += 1
        return res
