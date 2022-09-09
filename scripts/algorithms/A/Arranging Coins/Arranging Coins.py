# Runtime: 6683 ms (Top 5.01%) | Memory: 13.8 MB (Top 57.45%)
class Solution:
    def arrangeCoins(self, n: int) -> int:
        for i in range(1,2**31):
            val=i*(i+1)//2
            if val>n:
                a=i
                break
            elif val==n:
                return i
        return a-1