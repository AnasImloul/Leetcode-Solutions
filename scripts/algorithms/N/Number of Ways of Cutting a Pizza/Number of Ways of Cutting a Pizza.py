class Solution:
    def ways(self, p: List[str], k: int) -> int:
        m, n = len(p), len(p[0])
        apples = [[0 for _ in range(n+1)] for _ in range(m+1)] 
        # number of apples in (0,0) to (i,j)
        apples[1][1] = 0 if p[0][0] == '.' else 1
        for j in range(1,n):
            apples[1][j+1] = apples[1][j] if p[0][j] == '.' else apples[1][j] + 1
        for i in range(1,m):
            cur_apple = 0 if p[i][0] == '.' else 1
            apples[i+1][1] = apples[i][1] + cur_apple
            for j in range(1,n):
                if p[i][j] == 'A': cur_apple += 1
                apples[i+1][j+1] = apples[i][j+1] + cur_apple

        def getApples(x,y,z,w):
        # get the number of apples within range
        # x,y: top-left coordinates of current pizza
        # z,w: bottom-right
            return apples[z+1][w+1] + apples[x][y] - apples[z+1][y] - apples[x][w+1]

        @lru_cache(None)
        def cut(c,x,y,z,w):
        # c: number of cuts already cut
        # x,y: top-left coordinates of current pizza
        # z,w: bottom-right
            if c == k - 1:
                return 1 if getApples(x,y,z,w) > 0 else 0

            r = 0
            # horizontal cuts
            i = x
            while i < z:
                if getApples(x,y,i,w) > 0: break
                i += 1
            while i < z:
                r += cut(c+1,i+1,y,z,w)
                i += 1
            # vertical cuts
            j = y
            while j < w:
                if getApples(x,y,z,j) > 0: break
                j += 1
            while j < w:
                r += cut(c+1,x,j+1,z,w)
                j += 1

            return r

        return cut(0,0,0,m-1,n-1)%(10**9+7)