// Runtime: 2307 ms (Top 26.32%) | Memory: 38.70 MB (Top 25.26%)

from sortedcontainers import SortedList

class Solution:
    def minReverseOperations(self, n, p, banned_vals, K):
        remaining = [SortedList(), SortedList()]
        banned = set(banned_vals)
        for u in range(n):
            if u != p and u not in banned:
                remaining[u & 1].add(u)

        queue = [p]
        dist = [-1] * n
        dist[p] = 0
        for node in queue:
            lo = max(node - K + 1, 0)
            lo = 2 * lo + K - 1 - node
            hi = min(node + K - 1, n - 1) - (K - 1)
            hi = 2 * hi + K - 1 - node

            for nei in list(remaining[lo % 2].irange(lo, hi)):
                queue.append(nei)
                dist[nei] = dist[node] + 1
                remaining[lo % 2].remove(nei)
        
        return dist
