class Solution:
    def validPartition(self, n: List[int]) -> bool:
        @cache
        def dfs(i: int) -> bool:
            if i >= len(n) - 1:
                return i == len(n)
            two = n[i] == n[i + 1]
            three = i < len(n) - 2 and ((two and n[i + 1] == n[i + 2]) or (n[i] + 1 == n[i + 1] and n[i] + 2 == n[i + 2]))
            return (two and dfs(i + 2)) or (three and dfs(i + 3))
        return dfs(0)
