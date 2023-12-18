// Runtime: 324 ms (Top 44.4%) | Memory: 22.60 MB (Top 86.42%)

class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        head = list1
        for _ in range(a-1):
            head = head.next
        cur = head.next
        for _ in range(b-a):
            cur = cur.next
        head.next = list2
        while head.next:
            head = head.next
        if cur.next:
            head.next = cur.next
        return list1
