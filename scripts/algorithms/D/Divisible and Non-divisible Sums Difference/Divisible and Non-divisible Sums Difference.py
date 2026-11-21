# Runtime: 1 ms (Top 78.86%) | Memory: 19.20 MB (Top 39.65%)

class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        num1 = n * (n+1) / 2

        num2 = n // m
        num2 = m * num2 * (num2 + 1) / 2

        return int(num1 - 2 * num2)
