// Runtime: 118 ms (Top 25.36%) | Memory: 17.90 MB (Top 5.07%)

class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        nei = collections.defaultdict(set)
        for a, b in edges:
            nei[a].add(b)
            nei[b].add(a)
            
        visited, res = set(), 0.
        def dfs(leaf_id, p, time):
            nonlocal res
            if time >= t:
                if leaf_id == target: res = p
                return
            visited.add(leaf_id)
            neighbors = nei[leaf_id] - visited
            for n in neighbors or [leaf_id]:
                dfs(n, p / (len(neighbors) or 1), time + 1)
        dfs(1, 1, 0)
        return res
