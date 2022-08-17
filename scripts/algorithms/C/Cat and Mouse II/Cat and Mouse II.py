class Solution:
    def canMouseWin(self, A: List[str], cj: int, mj: int) -> bool:
        # some helper functions:
        xy2i = lambda x, y: x * n + y
        i2xy = lambda i: (i // n, i % n)
        def adj_grid(x0, y0, jump=1):
            for dx, dy in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                for step in range(jump):
                    x, y = x0 + (step+1) * dx, y0 + (step+1) * dy
                    if not(0<=x<m and 0<=y<n) or A[x][y]=="#": break
                    yield x, y
        
        m, n, jps = len(A), len(A[0]), (mj, cj)
        fi = mi = ci = 0  # location of food, mouse, cat
        for i in range(m):
            for j in range(n):
                if A[i][j] == "C": ci = xy2i(i, j)
                elif A[i][j] == "M": mi = xy2i(i, j)
                elif A[i][j] == "F": fi = xy2i(i, j)
		
		# BFS for unreachable food cases
        def reach_food(x, y):
            B = [list(row) for row in A]
            B[x][y] = "#"
            que = collections.deque([(x, y)])
            while que:
                for x, y in adj_grid(*que.popleft()):
                    if B[x][y] == "#": continue
                    if B[x][y] == "F": return True
                    B[x][y] = "#"
                    que.append((x, y))
            return False
        
        if not reach_food(*i2xy(mi)): return False
        elif not reach_food(*i2xy(ci)): return True
        
        # adjacent states counter
        adj = [[[0] * (m*n) for _ in range(m*n)] for _ in range(2)]
        for i0 in range(m*n):
            for k in (0, 1):
                i = [0, 0]
                i[k] = i0
                for x, y in adj_grid(*i2xy(i0), jps[k]):
                    adj[k][i[0]][i[1]] += 1
                i2 = i.copy()
                for i2[1-k] in range(m*n):
                    adj[k][i2[0]][i2[1]] = adj[k][i[0]][i[1]]
        
        dp = [[[None] * (m*n) for _ in range(m*n)] for _ in range(2)]
        que1, que2 = collections.deque(), collections.deque()  # que1 for decisive states, que2 for indecisive ones
        for i in range(m*n):
            x, y = i2xy(i)
            if A[x][y] == "#": continue
            if i != fi:
                dp[0][fi][i] = dp[1][fi][i] = True
                que1.append((1, fi, i))
                que2.append((0, fi, i))
            dp[0][i][fi] = dp[1][i][fi] = dp[0][i][i] = dp[1][i][i] = False
            que1.append((0,i,fi))
            que2.append((1,i,fi))
            que1.append((0,i,i))
            que2.append((1,i,i))
            
        while que1 or que2:
            while que1:
                k2, mi2, ci2 = que1.popleft()
                t = dp[k2][mi2][ci2]
                k = 1 - k2
                i = [mi2, ci2]
                for x, y in adj_grid(*i2xy(i[k]), jps[k]):
                    i[k] = xy2i(x, y)
                    if dp[k][i[0]][i[1]] is None:
                        dp[k][i[0]][i[1]] = t  # directly determine the value
                        if (k, i[0], i[1]) == (0, mi, ci): return t
                        que2.append((k, i[0], i[1]))
            while que2:
                k2, mi2, ci2 = que2.popleft()
                t = dp[k2][mi2][ci2]
                k = 1 - k2
                i = [mi2, ci2]
                for x, y in adj_grid(*i2xy(i[k]), jps[k]):
                    i[k] = xy2i(x, y)
                    if dp[k][i[0]][i[1]] is None:
                        adj[k][i[0]][i[1]] -= 1  # only change the counter
                        if adj[k][i[0]][i[1]] == 0:
                            dp[k][i[0]][i[1]] = t
                            if (k, i[0], i[1]) == (0, mi, ci): return t
                            que1.append((k, i[0], i[1]))
        
        return dp[0][mi][ci]
