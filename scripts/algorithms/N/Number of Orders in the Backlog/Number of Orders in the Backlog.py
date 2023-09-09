# Runtime: 689 ms (Top 70.7%) | Memory: 55.89 MB (Top 32.0%)

class Solution:
    def getNumberOfBacklogOrders(self, orders):
        b, s = [], []
        heapq.heapify(b)
        heapq.heapify(s)
        
        for p,a,o in orders:
            if o == 0:
                heapq.heappush(b, [-p, a])
                
            elif o == 1:
                heapq.heappush(s, [p, a])
            
            # Check "good" condition
            while s and b and s[0][0] <= -b[0][0]:
                a1, a2 = b[0][1], s[0][1]
                
                if a1 > a2:
                    b[0][1] -= a2
                    heapq.heappop(s)
                elif a1 < a2:
                    s[0][1] -= a1
                    heapq.heappop(b)
                else:
                    heapq.heappop(b)
                    heapq.heappop(s)
                    
        count = sum([a for p,a in b]) + sum([a for p,a in s])
        return count % (10**9 + 7)