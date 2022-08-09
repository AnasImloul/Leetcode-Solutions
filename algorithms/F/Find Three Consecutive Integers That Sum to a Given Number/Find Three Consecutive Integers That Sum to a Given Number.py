class Solution:
    def sumOfThree(self, num):
        if num % 3: return []
        x = num // 3
        return list(range(x-1,x+2))
