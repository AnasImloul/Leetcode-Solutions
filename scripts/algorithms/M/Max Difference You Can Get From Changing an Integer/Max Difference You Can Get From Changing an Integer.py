class Solution:
    def maxDiff(self, num: int) -> int:
        tmp = num
        xA, xB = 9, 1
        while tmp:
            digit = tmp % 10
            if digit != 9:
                xA = digit
            if digit > 1:
                xB = digit  
            tmp //= 10
        
        yA, yB = 9, 0 if digit == 1 and xB != 1 else 1
        digitPlace = 1
        a = b = 0
        while num:
            digit = num % 10
            a += digitPlace * (digit if digit != xA else yA)
            b += digitPlace * (digit if digit != xB else yB)
            num //= 10
            digitPlace *= 10
        
        return a - b