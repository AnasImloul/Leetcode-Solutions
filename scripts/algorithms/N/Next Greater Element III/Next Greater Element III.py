// Runtime: 42 ms (Top 26.09%) | Memory: 16.30 MB (Top 30.04%)

class Solution:
    def nextGreaterElement(self, n):
        digits = list(str(n))
        i = len(digits) - 1
        while i-1 >= 0 and digits[i] <= digits[i-1]:
            i -= 1
            
        if i == 0: return -1
        
        j = i
        while j+1 < len(digits) and digits[j+1] > digits[i-1]:
            j += 1
        
        digits[i-1], digits[j] = digits[j], digits[i-1]
        digits[i:] = digits[i:][::-1]
        ret = int(''.join(digits))
        
        return ret if ret < 1<<31 else -1
