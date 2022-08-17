class Solution:
    def getMinDistSum(self, positions: List[List[int]]) -> float:
        n = len(positions)
        if n == 1: return 0
        def gradient(x,y):
            ans = [0,0]
            for i in range(n):
                denom = math.sqrt(pow(x-positions[i][0],2)+pow(y-positions[i][1],2))
                ans[0] += (x-positions[i][0])/denom if denom else 0
                ans[1] += (y-positions[i][1])/denom if denom else 0
            return ans
        def fn(x, y):
            res = 0
            for i in range(n):
                res += math.sqrt(pow(x-positions[i][0],2)+pow(y-positions[i][1],2))
            return res
        x = sum(x for x,_ in positions)/n
        y = sum(y for _,y in positions)/n
        lr = 1
        while lr > 1e-7:
            dx, dy = gradient(x,y)
            x -= lr*dx
            y -= lr*dy
            lr *= 0.997
            if not dx and not dy:
                lr /= 2
        return fn(x,y)