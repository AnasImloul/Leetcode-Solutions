# Runtime: 2528 ms (Top 5.27%) | Memory: 54.6 MB (Top 10.20%)
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        min_res = math.inf
        min_point = max_point = last_point = None
        prev_val = head.val
        head = head.next
        i = 1
        while head.next:
            if ((head.next.val < head.val and prev_val < head.val) or
               (head.next.val > head.val and prev_val > head.val)):

                if min_point is None:
                    min_point = i
                else:
                    max_point = i

                if last_point:
                    min_res = min(min_res, i - last_point)

                last_point = i

            prev_val = head.val
            i += 1
            head = head.next

        if min_res == math.inf:
            min_res = -1
        max_res = max_point - min_point if max_point else -1

        return [min_res, max_res]