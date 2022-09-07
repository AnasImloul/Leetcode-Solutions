# Runtime: 997 ms (Top 62.25%) | Memory: 22.2 MB (Top 22.99%)
class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        def dfs(i, c):
            if color[i] != 0:
                if color[i] != c:
                    return False
                return True

            color[i] = c
            for u in e[i]:
                if not dfs(u, 3 - c):
                    return False
            return True

        e = [[] for _ in range(n)]
        for u, v in dislikes:
            u -= 1
            v -= 1
            e[u].append(v)
            e[v].append(u)
        color = [0] * n
        for i in range(n):
            if color[i] == 0:
                if not dfs(i, 1):
                    return False
        return True