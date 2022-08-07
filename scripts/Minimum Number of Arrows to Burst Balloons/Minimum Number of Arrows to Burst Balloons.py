class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        
        ans=[points[0]]
        for i in points[1:]:
            if(i[0]<=ans[-1][1]):
                ans[-1]=[ans[-1][0],min(ans[-1][1],i[1])]
            else:
                ans.append(i)
        return len(ans)
        
