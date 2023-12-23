// Runtime: 45 ms (Top 13.51%) | Memory: 17.40 MB (Top 21.17%)

class Solution:
    def middleNode(self, head):
        Iter, N = head, 0
        while Iter:
            Iter, N = Iter.next, N + 1
        for i in range(N//2):
            head = head.next
        return head
