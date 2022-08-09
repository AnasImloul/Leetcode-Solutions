class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        m = len(wall)
        ctr = {}
        res = m
        for i in range(m):
            n = len(wall[i])
            curr = 0
            for j in range(n - 1):
                curr += wall[i][j]
                x = ctr.get(curr, m) - 1
                ctr[curr] = x
                res = min(res, x)
        return res
