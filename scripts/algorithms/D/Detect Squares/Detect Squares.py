# Runtime: 658 ms (Top 42.61%) | Memory: 16 MB (Top 39.48%)
"""
Store every points and number of their appearance
Group the points by their x value

Given a point(x1,y1) to count, try to find p2(x1,y2),p3(x2,y2),p4(x2,y1)
and add product of their appearances

Go through every points that has same x1(except the point that is the same as (x1,y1), the length of the side of the square is decided by abd(y2-y1).

Use the decided side length to calculate p3 and p4, see if they are in the dict. If do, add product of their appearances.

p3 p2 p3`

p4 p1 p4`

Notice that p3 and p4 can be on both left side and right side of side (p2,p1)

"""
from collections import defaultdict
class DetectSquares:

    def __init__(self):
        self.pts=defaultdict(int)
        self.by_x=defaultdict(set)

    def add(self, point: List[int]) -> None:
        self.pts[(point[0],point[1])]+=1
        self.by_x[point[0]].add((point[0],point[1]))

    def count(self, p1: List[int]) -> int:
        res=0
        x1,y1=p1[0],p1[1]
        if x1 in self.by_x:
            #p2:x1,y2
            for p2 in self.by_x[x1]:
                x2,y2=p2
                if y1==y2:
                    continue
                #length of side of square
                b=abs(y1-y2)
                #left side
                p3=(x1-b,y2)
                p4=(x1-b,y1)
                if p3 in self.pts and p4 in self.pts:
                    res+=self.pts[p2]*self.pts[p3]*self.pts[p4]
                #right side
                p3=(x1+b,y2)
                p4=(x1+b,y1)
                if p3 in self.pts and p4 in self.pts:
                    res+=self.pts[p2]*self.pts[p3]*self.pts[p4]
        return res

# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)