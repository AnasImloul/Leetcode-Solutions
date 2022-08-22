# Runtime: 53 ms (Top 53.47%) | Memory: 13.8 MB (Top 76.51%)
# Definition for singly-linked list.
# class ListNode(object):
# def __init__(self, val=0, next=None):
# self.val = val
# self.next = next
class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        lessthan = []
        greateql = []

        while head:
            if head.val < x:
                lessthan.append(head.val)
            else:
                greateql.append(head.val)
            head = head.next

        h = res = ListNode()

        for i in range(len(lessthan)):
            res.next = ListNode(lessthan[i])
            res = res.next
        for i in range(len(greateql)):
            res.next = ListNode(greateql[i])
            res = res.next

        return h.next