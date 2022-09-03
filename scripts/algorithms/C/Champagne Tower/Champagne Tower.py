# Runtime: 392 ms (Top 9.30%) | Memory: 14.4 MB (Top 11.38%)
class Solution:
    def champagneTower(self, poured: int, r: int, c: int) -> float:
        quantity=defaultdict(int)
        quantity[(0,0)]=poured
        for i in range(r+1):
            flag=False
            for j in range(i+1):
                prev_flow=quantity[(i,j)]-1
                if prev_flow<=0:
                    continue
                flag=True
                quantity[(i,j)]=1
                quantity[(i+1,j)]+=prev_flow/2
                quantity[(i+1,j+1)]+=prev_flow/2
            if not flag: break
        return quantity[(r,c)]
