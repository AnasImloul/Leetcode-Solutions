class Solution:
    def isPathCrossing(self, path: str) -> bool:
        c = set()
        x,y = 0,0
        c.add((x,y))
        for i in path:
            if i == 'N':
                y+=1
            elif i == 'E':
                x+=1
            elif i == 'W':
                x-=1
            else:
                y-=1
            if (x,y) in c:
                return True
            else:
                c.add((x,y))
        return False
