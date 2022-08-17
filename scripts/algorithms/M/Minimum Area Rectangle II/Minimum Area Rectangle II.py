class Solution:
    def minAreaFreeRect(self, points: List[List[int]]) -> float:
        N = len(points)
        
        seen = set()
        for point in points:
            seen.add(tuple(point))

        # length^2
        def length2(a, b):
            return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1])
        
        best = 1e30
        for i in range(N):
            for j in range(N):
                if i == j:
                    continue
                
                lij = length2(points[i], points[j])
                for k in range(N):
                    if i == k or j == k:
                        continue
                    
                    # given i->j line, add to k to find l
                    dx, dy = points[j][0] - points[i][0], points[j][1] - points[i][1]
                    
                    pl = (points[k][0] + dx, points[k][1] + dy)
                    if pl not in seen:
                        continue
                    
                    lik = length2(points[i], points[k])
                    ljk = length2(points[j], points[k])

                    lil = length2(points[i], pl)
                    ljl = length2(points[j], pl)
                    lkl = length2(points[k], pl)
                    
                    if lij == lkl and lik == ljl and lil == ljk:
                        best = min(best, sqrt(lij * lik * lil) / sqrt(max(lij, lik, lil)))
                    
        if best >= 1e29:
            return 0
        return best
