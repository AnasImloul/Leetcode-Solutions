class Solution:
    def mostPoints(self, q: List[List[int]]) -> int:
        @cache
        def dfs(i: int) -> int:
            return 0 if i >= len(q) else max(dfs(i + 1), q[i][0] + dfs(i + 1 + q[i][1]))
        return dfs(0)
