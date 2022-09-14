# Runtime: 3258 ms (Top 98.66%) | Memory: 66 MB (Top 18.12%)
class Solution:
    def highestRankedKItems(self, G, pricing, start, k):
        m, n = len(G), len(G[0])
        row, col = start
        node = (0, G[row][col], row, col)
        visited = set()
        visited.add((row, col))
        d = deque([node])
        ans = []

        while d:
            dist, cost, row, col = d.popleft()
            if pricing[0] <= cost <= pricing[1]:
                ans += [(dist, cost, row, col)]

            for x, y in (row - 1, col), (row + 1, col), (row, col - 1), (row, col + 1):
                if 0 <= x <= m-1 and 0 <= y <= n-1 and (x, y) not in visited and G[x][y] != 0:
                    d.append((dist + 1, G[x][y], x, y))
                    visited.add((x, y))

        ans = sorted(ans)

        return [[x, y] for _, _, x, y in ans[:k]]