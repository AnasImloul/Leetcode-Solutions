# Runtime: 51 ms (Top 44.02%) | Memory: 13.7 MB (Top 94.97%)
class Solution:
    def sumOfThree(self, num):
        if num % 3: return []
        x = num // 3
        return list(range(x-1,x+2))