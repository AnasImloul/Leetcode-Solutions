class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        
        if n == 0:
            return 1
        
        table = [0]*(n+1)
        
        table[0] = 1
        table[1] = 9
        
        for i in range(2, n+1):
            table[i] = table[i-1]*(11-i)
        
        return sum(table)
