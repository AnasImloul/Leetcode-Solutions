class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        a,b,c=points
        return (b[1]-a[1])*(c[0]-b[0]) != (c[1]-b[1])*(b[0]-a[0])
