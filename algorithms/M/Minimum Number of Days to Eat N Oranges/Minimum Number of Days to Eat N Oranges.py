from collections import deque
from math import log2, ceil
class Solution:
    def minDays(self, n: int) -> int:
        maxd = 2*ceil(log2(n))
        que = deque([(1,1)])
        seen = set()
        while que:
            v, d = que.popleft()
            seen.add(v)
            if v == n:
                return d
            for w in [v+1, 2*v, 3*v]:
                if w not in seen and d <= maxd and w <= n:
                    que.append((w,d+1))
