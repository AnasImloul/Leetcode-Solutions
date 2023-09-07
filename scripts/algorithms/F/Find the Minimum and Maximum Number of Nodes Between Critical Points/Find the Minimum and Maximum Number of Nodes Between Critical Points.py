# Runtime: 687 ms (Top 71.4%) | Memory: 56.78 MB (Top 82.0%)

class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        idx, i = [], 1
        prev, cur = head, head.next
        while cur and cur.next:
            if prev.val < cur.val > cur.next.val or prev.val > cur.val < cur.next.val:
                idx.append(i)
            prev = cur
            cur = cur.next
            i += 1

        if len(idx) < 2:
            return [-1, -1]
        
        minDist = min(j - i for i, j in pairwise(idx))
        maxDist = idx[-1] - idx[0]

        return [minDist, maxDist]
