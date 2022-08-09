class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        def sq(a):
            return a * a

        def euclid(a, b, c, d):
            dist = sq(a - c) + sq(b - d)
            return sq(dist)

        n = len(points)
        res = 0
        for i in range(n):
            count = defaultdict(lambda : 0)
            for j in range(n):
                d = euclid(points[i][0], points[i][1], points[j][0], points[j][1])
                res += count[d] * 2
                count[d] += 1

        return res
