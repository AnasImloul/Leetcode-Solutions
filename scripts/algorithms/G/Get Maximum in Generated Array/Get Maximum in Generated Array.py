// Runtime: 34 ms (Top 84.4%) | Memory: 17.50 MB (Top 12.64%)

from queue import deque

class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        
        def arrgen(n):
            yield 0
            q = deque([1])
            while True:
                yield q[0]
                q.append(q[0])
                q.append(q[0]+q[1])
                q.popleft()
                
        g = arrgen(n)
        return max(next(g) for _ in range(n+1))