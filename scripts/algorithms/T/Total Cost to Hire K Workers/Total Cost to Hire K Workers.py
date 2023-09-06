# Runtime: 647 ms (Top 92.2%) | Memory: 27.10 MB (Top 57.3%)

class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        q = costs[:candidates]
        qq = costs[max(candidates, len(costs)-candidates):]
        heapify(q)
        heapify(qq)
        ans = 0 
        i, ii = candidates, len(costs)-candidates-1
        for _ in range(k): 
            if not qq or q and q[0] <= qq[0]: 
                ans += heappop(q)
                if i <= ii: 
                    heappush(q, costs[i])
                    i += 1
            else: 
                ans += heappop(qq)
                if i <= ii: 
                    heappush(qq, costs[ii])
                    ii -= 1
        return ans 