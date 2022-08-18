# Runtime: 59 ms (Top 77.27%) | Memory: 14.3 MB (Top 57.10%)

# Definition for singly-linked list.
# class ListNode:
# def __init__(self, val=0, next=None):
# self.val = val
# self.next = next
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        root = ListNode(0,head)
        summ , d , node = 0 , {} , root
        while node:
            summ += node.val
            if summ in d:
                prev = d[summ]
                tmp = prev.next
                tmp_sum = summ
                while tmp != node:
                    tmp_sum += tmp.val
                    if tmp_sum in d and d[tmp_sum] == tmp :d.pop(tmp_sum)
                    tmp = tmp.next
                prev.next = node.next
                node = prev
            else:
                d[summ] = node
            node = node.next

        return root.next