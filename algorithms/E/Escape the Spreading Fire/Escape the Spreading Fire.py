class Solution(object):
    def maximumMinutes(self, A):
        m, n = len(A), len(A[0])
        inf = 10 ** 10
        d = [[0,1],[1,0],[0,-1],[-1,0]]
        fires = [[i, j, 0] for i in range(m) for j in range(n) if A[i][j] == 1]
        A = [[inf if a < 2 else -1 for a in r] for r in A]

        def bfs(queue, seen):
            for i, j, t in queue:
                if seen[i][j] < inf: continue
                seen[i][j] = t
                for di,dj in d:
                    x, y = i + di, j + dj
                    if 0 <= x < m and 0 <= y < n and seen[x][y] >= inf and t + 1 < A[x][y]:
                        queue.append([x, y, t + 1])
        
        def die(t):
            seen = [[inf + 10] * n for i in range(m)]
            bfs([[0, 0, t]], seen)
            return seen[-1][-1] > A[-1][-1]

        bfs(fires, A)
        A[-1][-1] += 1
        return bisect_left(range(10**9 + 1), True, key=die) - 1
