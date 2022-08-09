class Solution:
    def minimumNumbers(self, num: int, k: int) -> int:
        if num == 0:
            return 0
        
        if k == 0:
            return 1 if num % 10 == 0 else -1
        
        for n in range(1, min(num // k, 10) + 1):
            if (num - n * k) % 10 == 0:
                return n
        
        return -1
