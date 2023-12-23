// Runtime: 35 ms (Top 75.17%) | Memory: 17.30 MB (Top 6.4%)

class Solution:
    def convertToBase7(self, num: int) -> str:
        
        if not num:
            return '0'
        
        sign = num < 0
        num = abs(num)
        
        stack = []
        while num:
            stack.append(str(num % 7))
            num = num // 7
        
        return '-'*sign + ''.join(stack[::-1])
