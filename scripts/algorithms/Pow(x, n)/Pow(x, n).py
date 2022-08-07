class Solution:
    def myPow(self, x: float, n: int) -> float:
        self.x = x
        
        if n == 0:
            return 1
        
        isInverted = False
        if n < 0:
            isInverted = True
            n = -1 * n

        result = self.pow(n)
        
        return result if not isInverted else 1 / result
        
    def pow(self, n):
        if n == 1:
            return self.x
        
        if n % 2 == 0:
            p = self.pow(n / 2)
            return p * p
        else:
            return self.x * self.pow(n-1)
