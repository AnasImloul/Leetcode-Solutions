class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        points = sorted(points, key=lambda item: (item[0], item[1]))
        cols = defaultdict(list)
        
        for x,y in points:
            cols[x].append(y)
        
        lastx = {}
        ans = float('inf')
        
        for x in cols:
            col = cols[x]
            for i, y1 in enumerate(col):
                for j in range(i):
                    y2 = col[j]
                    if (y2,y1) in lastx:
                        ans = min(ans, abs((x-lastx[y2,y1])*(y2-y1)))
                    lastx[y2,y1] = x
            
        return 0 if ans==float('inf') else ans