// Runtime: 45 ms (Top 20.34%) | Memory: 16.40 MB (Top 13.14%)

class Solution:
    def addDigits(self, num: int) -> int:
        while num > 9:
            num = num % 10 + num // 10
        return num
