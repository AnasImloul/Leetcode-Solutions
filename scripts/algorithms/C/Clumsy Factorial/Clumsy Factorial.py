# Runtime: 87 ms (Top 67.15%) | Memory: 13.9 MB (Top 59.65%)
class Solution:
    def clumsy(self, n: int) -> int:
        if(n>2):
            sum=n*(n-1)//(n-2)+(n-3)
        else:
            sum=n
        for i in range(n-4,0,-4):
            if(i<3):
                sum=sum-i
                break;
            sum=sum-(i)*(i-1)//(i-2)+(i-3)

        return sum