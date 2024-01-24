// Runtime: 1237 ms (Top 93.1%) | Memory: 79.90 MB (Top 68.97%)

from collections import defaultdict

class Solution:
  def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
    logs.sort(key=lambda x: x[1])  # (id, time)
    queries = sorted([(q, i) for i, q in enumerate(queries)])
    p1, p2, res = 0, 0, [0] * len(queries)
    sliding_servers = defaultdict(int)

    for q, pos in queries:
      while p2 < len(logs) and logs[p2][1] <= q:
        sliding_servers[logs[p2][0]] += 1
        p2 += 1
      
      while p1 < len(logs) and logs[p1][1] < q - x:
        if sliding_servers[logs[p1][0]] == 1:
          del sliding_servers[logs[p1][0]]
        else:
          sliding_servers[logs[p1][0]] -= 1
        p1 += 1
      
      res[pos] = n - len(sliding_servers)

    return res
