class Solution:
    def countLatticePoints(self, c: List[List[int]]) -> int:
        ans,m=0,[0]*40401
        c=set(((x,y,r) for x,y,r in c))
        for x, y, r in c:
            for i in range(x-r, x+r+1):
                d=int(sqrt(r*r-(x-i)*(x-i)))
                m[i*201+y-d:i*201+y+d+1]=[1]*(d+d+1)
        return sum(m)
