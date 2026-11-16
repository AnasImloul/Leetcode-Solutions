# Runtime: 499 ms (Top 38.14%) | Memory: 27.50 MB (Top 62.84%)

class Solution:
    def countBlackBlocks(self, m: int, n: int, coordinates: List[List[int]]) -> List[int]:
        counts=defaultdict(int)
        for x,y in coordinates:
            for i in range(max(0,x-1),min(m-1,x+1)):
                for j in range(max(0,y-1),min(n-1,y+1)):
                    counts[(i,j)]+=1


        ans=[0]*5 
        for count in counts.values():
            ans[count]+=1

        ans[0]=(m-1)*(n-1)-sum(ans)
        return ans
