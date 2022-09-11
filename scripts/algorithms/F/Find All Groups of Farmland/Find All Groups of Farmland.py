# Runtime: 1416 ms (Top 90.80%) | Memory: 33.1 MB (Top 49.64%)
class Solution:

    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        n = len(land)
        m = len(land[0])

        groups = []
        visited = set()

        for y in range(n):
            for x in range(m):
                if land[y][x] == 0:
                    continue

                if (y, x) in visited:
                    continue

                q = collections.deque()
                q.append((y, x))
                visited.add((y, x))

                while q:
                    cy, cx = q.popleft()

                    for dy, dx in ((0, 1), (1, 0)):
                        if (cy + dy, cx + dx) in visited:
                            continue

                        if 0 <= cy + dy < n and 0 <= cx + dx < m:
                            if land[cy + dy][cx + dx] == 1:
                                q.append((cy + dy, cx + dx))
                                visited.add((cy + dy, cx + dx))

                groups.append([y, x, cy, cx])

        return groups