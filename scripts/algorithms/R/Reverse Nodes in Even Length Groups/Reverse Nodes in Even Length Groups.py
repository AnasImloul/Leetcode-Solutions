# Runtime: 3864 ms (Top 51.07%) | Memory: 53.5 MB (Top 68.62%)
class Solution:
    def reverseEvenLengthGroups(self, head: Optional[ListNode]) -> Optional[ListNode]:
        group = 2
        tail = head # tail of previous group
        while tail and tail.next:
            cnt = 1 # actual size of the current group
            cur = tail.next # first node of the current group
            while cur.next and cnt < group:
                cur = cur.next
                cnt += 1
            pre, cur = tail, tail.next
            if cnt % 2 == 0: # if group size is even
                while cnt and cur:
                    nxt = cur.next
                    cur.next = pre
                    pre = cur
                    cur = nxt
                    cnt -= 1
                first = tail.next # first node of the original group
                first.next = cur
                tail.next = pre
                tail = first
            else:
                while cnt and cur:
                    pre, cur = cur, cur.next
                    cnt -= 1
                tail = pre
            group += 1
        return head