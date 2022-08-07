class Solution:
    def isUgly(self, n: int) -> bool:
        if n <= 0: return False
        
        while True:
            if n == 1: return True
            elif not n % 2: n /= 2
            elif not n % 3: n /= 3
            elif not n % 5: n /= 5
            else: return False
