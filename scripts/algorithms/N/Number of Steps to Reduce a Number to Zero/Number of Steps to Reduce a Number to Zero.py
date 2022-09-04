# Runtime: 70 ms (Top 5.12%) | Memory: 13.9 MB (Top 52.31%)
class Solution:
    def numberOfSteps(self, num: int) -> int:
        count=0
        while num:
            if num%2:
                num=num-1
            else:
                num=num//2
            count+=1
        return count